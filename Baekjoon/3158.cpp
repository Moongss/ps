#include <iostream>
#include <string>

int main() {
  std::string str;

  std::cin >> str;

  int end = str.length() - 1;
  int now = str[end] - '0';
  if (now == 4) {
    std::cout << str.substr(0, end) << "1\n";
    std::cout << str.substr(0, end) << "2\n";
    std::cout << str.substr(0, end) << "3\n";
    return 0;
  }

  bool num1 = false, num2 = false, num3 = false;
  while (end >= 1) {
    now = str[end] - '0';
    if (!num1 && now == 1) {
      std::cout << str.substr(0, end) << "4\n";
      num1 = !num1;
    }
    if (!num2 && now == 2) {
      std::cout << str.substr(0, end) << "4\n";
      num2 = !num2;
    }
    if (!num3 && now == 3) {
      std::cout << str.substr(0, end) << "4\n";
      num3 = !num3;
    }
    end--;
  }
  return 0;
}