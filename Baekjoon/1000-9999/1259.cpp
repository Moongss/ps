#include <iostream>
#include <string>

int main() {
  std::string numSequence;
  bool isPalindrome;

  while (true) {
    std::cin >> numSequence;
    int sequenceLength = numSequence.length();
    if (sequenceLength == 1 && numSequence[0] == '0') break;

    isPalindrome = true;
    for (int i = 0; i < sequenceLength / 2; i++) {
      if (numSequence[i] != numSequence[sequenceLength - 1 - i]) {
        isPalindrome = false;
        break;
      }
    }

    if (isPalindrome)
      std::cout << "yes" << std::endl;
    else
      std::cout << "no" << std::endl;
  }

  return 0;
}