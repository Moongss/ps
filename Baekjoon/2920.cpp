#include <iostream>

int main() {
  
  int code[8];

  for (int i = 0; i < 8; i++) {
    std::cin >> code[i];
  }

  bool isAscending = true;
  bool isDescending = true;

  for (int i = 1; i <= 8; i++) {
    if (code[i - 1] != i) {
      isAscending = false;
      break;
    }
  }

  for (int i = 8; i >= 1; i--) {
    if (code[8 - i] != i) {
      isDescending = false;
      break;
    }
  }

  if (isAscending)
    std::cout << "ascending\n";
  else if (isDescending)
    std::cout << "descending\n";
  else
    std::cout << "mixed\n";

  return 0;
}