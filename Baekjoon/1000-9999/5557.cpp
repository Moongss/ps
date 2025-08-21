#include <iostream>
#define MIN 0
#define MAX 20

int N;
int input[101];
long long dp[101][21] = {
    0,
};

int main() {
  std::cin >> N;

  for (int i = 1; i <= N; i++) {
    std::cin >> input[i];
  }

  dp[1][input[1]] = 1;
  for (int i = 2; i < N; i++) {
    for (int j = MIN; j <= MAX; j++) {
      int addResult = j + input[i];
      int subResult = j - input[i];

      if (dp[i - 1][j] && addResult <= MAX)
        dp[i][addResult] += dp[i - 1][j];
      if (dp[i - 1][j] && subResult >= MIN)
        dp[i][subResult] += dp[i - 1][j];
    }
  }

  std::cout << dp[N - 1][input[N]] << std::endl;
  return 0;
}