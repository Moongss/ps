#include <iostream>
#define MAX 10001

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

  for (int i = 1; i <= K; i++) {
    dp[i] = MAX;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = input[i]; j <= K; j++) {
      int prevIdx = j - input[i];
      if (prevIdx >= 0) {
        if (dp[j] > 1 + dp[prevIdx]) { // dp[j] > 0
          dp[j] = 1 + dp[prevIdx];
        }
      }
    }
  }

  // for (int i = 1; i <= 15; i++) {
  //   std::cout << "dp[" << i << "] : " << dp[i] << std::endl;
  // }

  if (dp[K] == MAX)
    std::cout << -1 << std::endl;
  else
    std::cout << dp[K] << std::endl;
  return 0;
}