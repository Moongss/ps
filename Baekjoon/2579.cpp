#include <iostream>

int max(int a, int b) {
  return (a > b ? a : b);
}

int main() {
  int dp[301] = {0};
  int input[301] = {0};
  int N;

  std::cin >> N;
  for (int i = 1; i <= N; i++)
    std::cin >> input[i];

  dp[1] = input[1];
  dp[2] = input[1] + input[2];
  dp[3] = max(input[1] + input[3], input[2] + input[3]);

  //dp에서 원본 데이터를 사용한다는 개념이 미숙했음.
  //반복 구간을 잘 파악하는게 핵심인 것 같다. 패턴찾기
  for (int i = 4; i <= N; i++) {
    dp[i] = max(dp[i - 2] + input[i], dp[i - 3] + input[i - 1] + input[i]);
  }

  std::cout << dp[N];
  return 0;
}