#include <iostream>

int main() {
  int a, b, result;

  std::cin >> a >> b;
  result = a * b;

  while (b > 0) {
    std::cout << a * (b % 10) << std::endl;
    b /= 10;
  }
  std::cout << result << std::endl;
  return 0;
}