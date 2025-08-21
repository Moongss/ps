#include <algorithm>
#include <iostream>

int N, Q;
long long tree[4000004] = {
    0,
};

long long sum(int start, int end, int left, int right, int node) {
  if (right < start || end < left)
    return 0;
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  return sum(start, mid, left, right, node * 2) +
         sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int idx, int diff, int node) {
  if (idx < start || end < idx)
    return;

  tree[node] += diff;
  if (start == end)
    return;
  int mid = (start + end) / 2;
  update(start, mid, idx, diff, node * 2);
  update(mid + 1, end, idx, diff, node * 2 + 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> Q;

  int flag, p, q;
  for (int i = 0; i < Q; i++) {
    std::cin >> flag >> p >> q;
    if (flag == 1) {
      update(1, N, p, q, 1);
    } else {
      std::cout << sum(1, N, p, q, 1) << "\n";
    }
  }
  return 0;
}