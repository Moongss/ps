#include <iostream>

#define RANGE_OUT_MIN 1000000001
#define RANGE_OUT_MAX 0

typedef long long ll;
typedef std::pair<int, int> elem;

int arr[100001];
elem tree[400004];
int N, M;

elem getMinMax(elem a, elem b) {
  elem result = b;
  if (a.first < b.first)
    result.first = a.first;
  if (a.second > b.second)
    result.second = a.second;

  return result;
}

elem init(int start, int end, int node) {
  if (start == end)
    return tree[node] = {arr[start], arr[start]};

  int mid = (start + end) / 2;

  elem leftChild = init(start, mid, node * 2);
  elem rightChild = init(mid + 1, end, node * 2 + 1);

  return tree[node] = getMinMax(leftChild, rightChild);
}

elem findMinMax(int start, int end, int left, int right, int node) {
  if (left > end || start > right)
    return {RANGE_OUT_MIN, RANGE_OUT_MAX};
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  elem leftChild = findMinMax(start, mid, left, right, node * 2);
  elem rightChild = findMinMax(mid + 1, end, left, right, node * 2 + 1);

  return getMinMax(leftChild, rightChild);
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

    elem result = findMinMax(1, N, left, right, 1);
    std::cout << result.first << " " << result.second << "\n";
  }

  return 0;
}