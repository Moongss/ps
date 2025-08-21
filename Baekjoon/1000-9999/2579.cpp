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

  //dp���� ���� �����͸� ����Ѵٴ� ������ �̼�����.
  //�ݺ� ������ �� �ľ��ϴ°� �ٽ��� �� ����. ����ã��
  for (int i = 4; i <= N; i++) {
    dp[i] = max(dp[i - 2] + input[i], dp[i - 3] + input[i - 1] + input[i]);
  }

  std::cout << dp[N];
  return 0;
}