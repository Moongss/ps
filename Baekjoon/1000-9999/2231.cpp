#include <iostream>

bool isConstructor(int TargetNum, int currentNum) {
  int sum = currentNum;

  while (currentNum > 0) {
    sum += currentNum % 10;
    currentNum /= 10;
  }

  if (TargetNum == sum) return true;
  return false;
}

int main() {
  int num;

  std::cin >> num;

  for (int i = 1; i <= num; i++) {
    if (isConstructor(num, i)) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << 0 << std::endl;
  return 0;
}