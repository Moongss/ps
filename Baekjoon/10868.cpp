#include <iostream>

#define RANGE_OUT_MIN 1000000001

typedef long long ll;

int arr[100001];
int tree[400004];
int N, M;

int min(int a, int b) {
  if (a < b)
    return a;
  return b;
}

int init(int start, int end, int node) {
  if (start == end)
    return tree[node] = arr[start];

  int mid = (start + end) / 2;

  int leftChild = init(start, mid, node * 2);
  int rightChild = init(mid + 1, end, node * 2 + 1);

  return tree[node] = min(leftChild, rightChild);
}

int findMin(int start, int end, int left, int right, int node) {
  if (left > end || start > right)
    return RANGE_OUT_MIN;
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  int leftChild = findMin(start, mid, left, right, node * 2);
  int rightChild = findMin(mid + 1, end, left, right, node * 2 + 1);

  return min(leftChild, rightChild);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    std::cin >> arr[i];
  }
  init(1, N, 1);

  for (int i = 1; i <= M; i++) {
    int left, right;
    std::cin >> left >> right;

    int result = findMin(1, N, left, right, 1);
    std::cout << result << "\n";
  }

  return 0;
}