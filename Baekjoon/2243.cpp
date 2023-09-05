#include <algorithm>
#include <iostream>

int N;
int A, B, C;
int tree[4000004] = {
    0,
};

void update(int start, int end, int node, int target, int diff) {
  if (target < start || target > end)
    return;

  tree[node] += diff;
  if (start == end)
    return;

  int mid = (start + end) / 2;
  update(start, mid, node * 2, target, diff);
  update(mid + 1, end, node * 2 + 1, target, diff);
}

int query(int start, int end, int node, int rank) {
  if (start == end)
    return start;

  int mid = (start + end) / 2;
  if (rank <= tree[node * 2])
    return query(start, mid, node * 2, rank);
  else
    return query(mid + 1, end, node * 2 + 1, rank - tree[node * 2]);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> A;
    if (A == 1) {
      std::cin >> B;
      int result = query(1, 1000000, 1, B);
      std::cout << result << "\n";
      update(1, 1000000, 1, result, -1);
    } else {
      std::cin >> B >> C;
      update(1, 1000000, 1, B, C);
    }
  }

  return 0;
}