#include <iostream>

int dp[16][16] = {
    0,
};

int main() {
  int N, M, K;
  int KCoord[2];

  std::cin >> N >> M >> K;
  KCoord[0] = (K - 1) / M + 1;
  KCoord[1] = (K - 1) % M + 1;

  for (int i = 1; i <= N; i++) {
    dp[i][1] = 1;
  }
  for (int i = 1; i <= M; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    for (int j = 2; j <= M; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  if (K)
    std::cout << dp[KCoord[0]][KCoord[1]] *
                     dp[N - KCoord[0] + 1][M - KCoord[1] + 1]
              << std::endl;
  else
    std::cout << dp[N][M] << std::endl;
  return 0;
}