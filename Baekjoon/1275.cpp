#include <iostream>

typedef long long ll;

int arr[100001];
ll tree[400004];
int N, Q;

ll init(int start, int end, int node) {
  if (start == end)
    return tree[node] = arr[start];

  int mid = (start + end) / 2;
  return tree[node] =
             init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int left, int right, int node) {
  if (left > end || start > right)
    return 0;
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  return sum(start, mid, left, right, node * 2) +
         sum(mid + 1, end, left, right, node * 2 + 1);
}

ll update(int start, int end, int target, int node) {
  if (target < start || target > end)
    return tree[node];
  if (start == end) {
    return tree[node] = arr[target];
  }

  int mid = (start + end) / 2;
  return tree[node] = update(start, mid, target, node * 2) +
                      update(mid + 1, end, target, node * 2 + 1);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> Q;

  for (int i = 1; i <= N; i++) {
    std::cin >> arr[i];
  }

  init(1, N, 1);
  for (int i = 0; i < Q; i++) {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    if (x > y) {
      int tmp = x;
      x = y;
      y = tmp;
    }
    std::cout << sum(1, N, x, y, 1) << "\n";
    arr[a] = b;
    update(1, N, a, 1);
  }

  return 0;
}