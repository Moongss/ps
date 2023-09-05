#include <iostream>

int main() {
  
  int input;
  int N;
  int max = -1000001;
  int min = 1000001;
  
  std::cin >> N;
  while (N--) {
    std::cin >> input;
    max = (input > max) ? input : max;
    min = (input < min) ? input : min;
  }

  std::cout << min << " " << max << std::endl;
  return 0;
}