#include <iostream>

int main() {
  
  int maxValue = 0;
  int maxIndex = 0;
  int input;

  for (int i = 1; i <= 9; i++) {
    std::cin >> input;
    if (maxValue < input) {
      maxValue = input;
      maxIndex = i;
    }
  }

  std::cout << maxValue << std::endl;
  std::cout << maxIndex << std::endl;
}