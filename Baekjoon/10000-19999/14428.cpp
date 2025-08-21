#include <iostream>

#define UPDATE 1

typedef long long ll;

int arr[100001];
int tree[400004];

int N, M;

int init(int start, int end, int node) {
  if (start == end)
    return tree[node] = start;

  int mid = (start + end) / 2;
  int left = init(start, mid, node * 2);
  int right = init(mid + 1, end, node * 2 + 1);

  if (arr[left] <= arr[right])
    tree[node] = left;
  else
    tree[node] = right;
  return tree[node];
}

int update(int start, int end, int target, int node) {
  if (target < start || end < target) // to reduce branch?
    return tree[node];
  if (start == end)
    return tree[node];

  int mid = (start + end) / 2;
  int leftChild = update(start, mid, target, node * 2);
  int rightChild = update(mid + 1, end, target, node * 2 + 1);
  if (arr[leftChild] < arr[rightChild] ||
           arr[leftChild] == arr[rightChild] && leftChild < rightChild) {
    return tree[node] = leftChild;
  }
  return tree[node] = rightChild;
}

int getMinIdx(int start, int end, int left, int right, int node) {
  if (left > end || start > right)
    return -1;
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  int leftChild = getMinIdx(start, mid, left, right, node * 2);
  int rightChild = getMinIdx(mid + 1, end, left, right, node * 2 + 1);

  if (leftChild == -1)
    return rightChild;
  else if (rightChild == -1)
    return leftChild;
  else if (arr[leftChild] < arr[rightChild] ||
           arr[leftChild] == arr[rightChild] && leftChild < rightChild)
    return leftChild;
  return rightChild;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> arr[i];
  }

  init(1, N, 1);

  std::cin >> M;
  for (int i = 0; i < M; i++) {
    int flag;

    std::cin >> flag;
    if (flag == UPDATE) {
      int idx, v;
      std::cin >> idx >> v;
      arr[idx] = v;
      update(1, N, idx, 1);
    } else {
      int left, right;
      std::cin >> left >> right;
      std::cout << getMinIdx(1, N, left, right, 1) << "\n";
    }
  }
  return 0;
}