#include <iostream>

typedef long long ll;

int arr[100001];
int tree[400004];

int N;

int init(int start, int end, int node) {
  if (start == end)
    return tree[node] = start;

  int mid = (start + end) / 2;
  int left = init(start, mid, node * 2);
  int right = init(mid + 1, end, node * 2 + 1);

  if (arr[left] < arr[right])
    tree[node] = left;
  else
    tree[node] = right;
  return tree[node];
}

int query(int start, int end, int left, int right, int node) {
  if (left > end || start > right)
    return -1;
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  int leftNode = query(start, mid, left, right, node * 2);
  int rightNode = query(mid + 1, end, left, right, node * 2 + 1);

  if (leftNode == -1)
    return rightNode;
  else if (rightNode == -1)
    return leftNode;
  else if (arr[leftNode] < arr[rightNode])
    return leftNode;
  return rightNode;
}

ll solve(int left, int right) {
  int heightIdx = query(1, N, left, right, 1);
  int width = right - left + 1;
  ll area = (ll)width * (ll)arr[heightIdx];

  if (left < heightIdx) {
    ll tmp = solve(left, heightIdx - 1);
    if (area < tmp)
      area = tmp;
  }
  if (right > heightIdx) {
    ll tmp = solve(heightIdx + 1, right);
    if (area < tmp)
      area = tmp;
  }
  return area;
}

int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> arr[i];
  }

  init(1, N, 1);
  std::cout << solve(1, N) << std::endl;
}