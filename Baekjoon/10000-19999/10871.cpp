#include <iostream>

int main() {
  
  int N, max;
  int input;

  std::cin >> N >> max;
  for (int i = 0; i < N; i++) {
    std::cin >> input;
    if (input < max)
      std::cout << input << " ";
  }
  std::cout << std::endl;

  return 0;
}