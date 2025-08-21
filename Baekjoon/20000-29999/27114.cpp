#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 42424242
int A, B, C, K;
std::vector<std::pair<int, int>> turns; // BB, LLLL, RRRR, LR, LLB, RRB

int dp[1000002] = {
    0,
};

void init() {
  for (int i = 0; i <= K; i++) {
    dp[i] = INF;
  }

  //미리 정렬해두기
  turns.push_back({C * 2, 2});     // BB
  turns.push_back({A + B, 2});     // LR
  turns.push_back({A * 2 + C, 3}); // LLB
  turns.push_back({B * 2 + C, 3}); // RRB
  turns.push_back({A * 4, 4});     // LLLL
  turns.push_back({B * 4, 4});     // RRRR
}

void solve() {
  std::queue<int> q;
  dp[0] = 0;

  q.push(0);
  while (!q.empty()) {
    int elem = q.front();
    q.pop();

    if (elem == K) {
      continue;
    }

    for (int i = 0; i < turns.size(); i++) {
      int turnCost = turns[i].first;
      int turnCnt = turns[i].second;

      int updateNum = elem + turnCost;
      if (updateNum <= K) {
        if (dp[updateNum] > dp[elem] + turnCnt) {
          dp[updateNum] = dp[elem] + turnCnt;
          q.push(updateNum);
        }
      }
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> A >> B >> C >> K;

  init();
  solve();

  if (dp[K] == INF)
    std::cout << -1 << std::endl;
  else
    std::cout << dp[K] << std::endl;
  return 0;
}