#include <iostream>

int N;
int result;

int main() {
  std::cin >> N;

  result = 0;
  for (int i = 0; i < N; i++) {
    int tmp;
    std::cin >> tmp;

    if (tmp - (N - i) > result)
      result = tmp - (N - i);
  }

  std::cout << result << std::endl;

  return 0;
}