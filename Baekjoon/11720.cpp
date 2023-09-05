#include <iostream>
#include <string>

int main() {
  
  int len;
  int sum = 0;
  std::string numList;

  std::cin >> len >> numList;

  while (len) {
    len--;
    sum += (numList[len] - '0');
  }
  std::cout << sum << std::endl;
  return 0;
}