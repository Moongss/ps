#include <iostream>

int dp[10001] = {
    0,
};
int input[101] = {
    0,
};

int N, K;

int main() {
  std::cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    std::cin >> input[i];
  }
  dp[0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = input[i]; j <= K; j++) {
      int prevIdx = j - input[i];
      if (prevIdx >= 0)
        dp[j] += dp[prevIdx];
    }
  }

  std::cout << dp[K] << std::endl;
  return 0;
}