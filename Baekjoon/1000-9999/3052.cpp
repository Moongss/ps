#include <iostream>

int main() {
  
  int cnt = 0;
  int input[10];
  bool isExistValue[42] = {false};

  for (int i = 0; i < 10; i++) {
    std::cin >> input[i];
    input[i] %= 42;
    if (!isExistValue[input[i]]) {
      isExistValue[input[i]] = true;
      cnt++;
    }
  }

  std::cout << cnt << std::endl;

  return 0;
}