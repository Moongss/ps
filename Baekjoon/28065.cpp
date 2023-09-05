#include <iostream>

int N;
int main() {
  std::cin >> N;

  if (N % 2 == 0) {
    int start = N;
    int end = 1;

    while (start > end) {
      std::cout << start << " " << end << " ";
      start--, end++;
    }
  } else {
    int start = 1;
    int end = N;

    while (start < end) {
      std::cout << start << " " << end << " ";
      start++, end--;
    }
    std::cout << start;
  }
  std::cout << std::endl;
  return 0;
}