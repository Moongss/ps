#include <iostream>

int main(void) {
  int dp[21] = {0};
  int n;

  dp[0] = 0;
  dp[1] = 1;

  std::cin >> n;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  std::cout << dp[n];
  return 0;
}