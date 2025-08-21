#include <iostream>

int main() {
  int N, K;
  int result = 1;

  std::cin >> N >> K;
  for (int i = 0; i < K; i++) result *= (N - i);
  for (int i = 1; i <= K; i++) result /= i;

  std::cout << result << std::endl;
  return 0;
}