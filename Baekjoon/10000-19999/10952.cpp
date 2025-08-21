#include <iostream>

int main() {
  
  int A, B;
  while (true) {
    std::cin >> A >> B;
    if (A + B == 0)
      break;
    std::cout << A + B << std::endl;
  }
  
  return 0;
}