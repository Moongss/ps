#include <iostream>

int main() {
  int N, P;
  long long result = 1;

  std::cin >> N >> P;
  for (int i = 1; i <= N; i++) {
    result = (result * (i % P)) % P;
  }

  std::cout << result << std::endl;
  return 0;
}