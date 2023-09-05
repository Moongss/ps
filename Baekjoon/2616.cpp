#include <iostream>

int N;
int K;
int dp[2][50001] = {
    0,
};
int sum[50001] = {
    0,
};

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> sum[i];
    sum[i] += sum[i - 1];
  }
  std::cin >> K;

  for (int i = 1; i <= 3; i++) {       // 1 ~ 3
    for (int j = i * K; j <= N; j++) { // 1~N
      dp[i % 2][j] =
          max(dp[i % 2][j - 1],
              dp[(i - 1) % 2][j - K] + (sum[j] - sum[j - K])); // i >= 0
    }
  }

  std::cout << dp[1][N];
  return 0;
}