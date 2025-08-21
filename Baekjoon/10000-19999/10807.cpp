#include <iostream>

int N, v;
int arr[100];
int main() {
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }
  std::cin >> v;

  int result = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i] == v)
      result++;
  }

  std::cout << result << std::endl;
  return 0;
}