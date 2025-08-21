#include <iostream>

int main() {
  
  int input;
  std::cin >> input;

  for (int i = 1; i <= 9; i++) {
    std::cout << input << " * " << i << " = " << input * i << std::endl;
  }
  return 0;
}