#include <iostream>

int T;

int main() {
  std::cin >> T;
  while (T--) {
    int N;
    std::cin >> N;

    int sum = 0;
    int pSum[1001] = {
        0,
    };
    for (int i = 1; i <= N; i++) {
      std::cin >> pSum[i];
      pSum[i] += pSum[i - 1];
    }

    int result = -42424242;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        int tmp = pSum[j] - pSum[i];
        if (tmp > result)
          result = tmp;
      }
    }
    std::cout << result << std::endl;
  }
  return 0;
}