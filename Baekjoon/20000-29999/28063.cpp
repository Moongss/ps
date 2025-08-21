#include <iostream>

int N;
int x, y;

int main() {
  std::cin >> N;
  std::cin >> x >> y;

  if (N == 1)
    std::cout << 0 << std::endl;
  else {
    if (x == 1 && y == 1 || x == 1 && y == N || x == N && y == 1 ||
        x == N && y == N)
      std::cout << 2 << std::endl;
    else if (x == 1 || x == N || y == 1 || y == N)
      std::cout << 3 << std::endl;
    else
      std::cout << 4 << std::endl;
  }

  return 0;
}