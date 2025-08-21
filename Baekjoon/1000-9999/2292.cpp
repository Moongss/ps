#include <iostream>

int main() {
  int N;
  int test = 6;
  int cnt = 1;
  std::cin >> N;
  N -= 2;

  for (int i = 2; N >= 0; i++) {
    cnt++;
    if (N < test) {
      break;
    }
    test += i * 6;
  }
  std::cout << cnt << std::endl;
  return 0;
}