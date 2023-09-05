#include <cmath>
#include <cstring>
#include <iostream>

#define INF 42424242;
int N;
int dp[16][1 << 16];
int map[16][16];

int solve(int node, int bit) {
  if (bit == (1 << N) - 1) { // 0 ~ 15
    if (map[node][0] > 0) //�湮 �� �ߴµ�, ù ���� ���� ��찡 �ִٸ�.
      return map[node][0]; //�̰� �ּҰ���. not return dp[node][0]
    return INF;
  }

  if (dp[node][bit] != 0)
    return dp[node][bit];
  dp[node][bit] = INF;

  for (int i = 0; i < N; i++) {
    if (map[node][i] == 0)
      continue;
    if (bit & (1 << i))
      continue;
    dp[node][bit] =
        std::min(dp[node][bit], map[node][i] + solve(i, bit | (1 << i)));
  }

  return dp[node][bit];
}

int main() {
  std::cin >> N;

  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> map[i][j];
    }
  }

  std::cout << solve(0, 1) << std::endl;
  return 0;
}