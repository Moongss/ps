#include <iostream>

int main() {
  int x, y;
  int result = 0;

  std::cin >> x >> y;
  if (x > 0) {
    if (y > 0)
      result = 1;
    else
      result = 4;
  } else {
    if (y > 0)
      result = 2;
    else
      result = 3;
  }

  std::cout << result << std::endl;
  return 0;
}