#include <iostream>

int main() {
  int divisorCnt;
  int divisor;
  std::cin >> divisorCnt;

  int max = 1;
  int min = 1000001;
  for (int i = 0; i < divisorCnt; i++) {
    std::cin >> divisor;
    max = (max < divisor) ? divisor : max;
    min = (min > divisor) ? divisor : min;
  }

  std::cout << max * min << std::endl;
  return 0;
}