#include <algorithm>
#include <iostream>

int r[501];
int c[501];
int dp[501][501];
int N;

#define INF 2147483647

int main() {
  std::cin >> N;

  for (int i = 1; i <= N; i++) {
    std::cin >> r[i] >> c[i];
  }

  // i, j
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j + i <= N; j++) {
      int start = j;
      int end = i + j;

      dp[start][end] = INF;
      for (int k = start; k < end; k++) {
        int newCost = dp[start][k] + dp[k + 1][end] + r[start] * c[k] * c[end];
        dp[start][end] = std::min(dp[start][end], newCost);
      }
    }
  }

  std::cout << dp[1][N];
  return 0;
}