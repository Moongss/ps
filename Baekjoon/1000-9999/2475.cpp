#include <iostream>

int main() {
  
  int anwser = 0;
  int input;
  for (int i = 0; i < 5; i++) {
    std::cin >> input;
    anwser += (input * input) % 10;
  }

  std::cout << anwser % 10;
}