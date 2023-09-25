#include <iostream>

#define UPDATE 1

typedef long long ll;
typedef std::pair<int, int> pair;

int tree[4000004] = {0, };
int N, M;

void update(int start, int end, int target, int node) {
  if (target < start || end < target)
    return ;
  if (start == end) {
    tree[node]++;
    return ;
  }

  int mid = (start + end) / 2;
  update(start, mid, target, node * 2); 
  update(mid + 1, end, target, node * 2 + 1); 
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int solve(int start, int end, int target, int node) {
  if (target < start || end < target)

  int mid = (start + end) / 2;
  solve(start, mid, target, node * 2);
  solve(mid + 1, end, target, node * 2 + 1);
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
  for (int i = 1; i <= N; i++) {
    solve(1, i, i, 1);
  }
  std::cout << result << std::endl;
  return 0;
}