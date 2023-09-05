#include <iostream>

int main() {
  int dp[1000001] = {0};
  int N;

  dp[1] = 1;
  dp[2] = 2;
  
  std::cin >> N;

  for (int i = 3; i <= N; i++)
    dp[i] = (dp[i - 1]  + dp[i - 2]) % 15746;
  
  std::cout << dp[N] % 15746;

  return 0;
} 