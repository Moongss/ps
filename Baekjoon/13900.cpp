#include <iostream>

int N;
int input[100001];
long long dp[100001] = {
    0,
};
int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> input[i];
    dp[i] = dp[i - 1] + input[i];
  }

  long long result = 0;
  for (int i = 1; i <= N - 1; i++) {
    result += input[i] * (dp[N] - dp[i]);
  }
  std::cout << result << std::endl;
  return 0;
}