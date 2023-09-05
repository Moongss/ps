#include <iostream>

#define UPDATE 1
#define EVEN 2
#define ODD 3

typedef long long ll;
typedef std::pair<int, int> elem;

int arr[100001];
elem tree[400004];

int N, M;

elem init(int start, int end, int node) {
  if (start == end)
    return tree[node] = {(arr[start] % 2 == 0), (arr[start] % 2 == 1)};

  int mid = (start + end) / 2;

  elem left = init(start, mid, node * 2);
  elem right = init(mid + 1, end, node * 2 + 1);

  return tree[node] = {left.first + right.first, left.second + right.second};
}

void update(int start, int end, int targetIdx, int evenDiff, int oddDiff,
            int node) {
  if (targetIdx < start || end < targetIdx)
    return;

  tree[node] = {tree[node].first + evenDiff, tree[node].second + oddDiff};
  int mid = (start + end) / 2;
  if (start == end)
    return;
  update(start, mid, targetIdx, evenDiff, oddDiff, node * 2);
  update(mid + 1, end, targetIdx, evenDiff, oddDiff, node * 2 + 1);
}

int getCnt(int start, int end, int left, int right, int query, int node) {
  if (left > end || start > right)
    return 0;
  if (left <= start && end <= right) {
    if (query == EVEN)
      return tree[node].first;
    else
      return tree[node].second;
  }

  int mid = (start + end) / 2;
  return getCnt(start, mid, left, right, query, node * 2) +
         getCnt(mid + 1, end, left, right, query, node * 2 + 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 1; i <= N; i++)
    std::cin >> arr[i];
  init(1, N, 1);

  std::cin >> M;
  for (int i = 0; i < M; i++) {
    int query;
    std::cin >> query;

    if (query == EVEN || query == ODD) {
      int left, right;
      std::cin >> left >> right;
      std::cout << getCnt(1, N, left, right, query, 1) << "\n";
    } else {
      int targetIdx, value;
      std::cin >> targetIdx >> value;
      if (arr[targetIdx] % 2 != value % 2) {
        if (arr[targetIdx] % 2 == 0) // update value is odd.
          update(1, N, targetIdx, -1, 1, 1);
        else
          update(1, N, targetIdx, 1, -1, 1);
      }
      arr[targetIdx] = value;
    }
  }
  return 0;
}
