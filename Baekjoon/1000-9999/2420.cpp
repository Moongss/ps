#include <iostream>

long long abs(long long a, long long b) {
  if (a - b < 0)
    return -(a - b);
  return a - b;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << abs(a, b) << std::endl;

  return 0;
}