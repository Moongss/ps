#include <iostream>
#include <string>

int main() {
  int N, M;
  int numList[100];
  int currentMax = 0;

  std::cin >> N >> M;
  for (int i = 0; i < N; i++) std::cin >> numList[i];

  int currentSum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        currentSum = numList[i] + numList[j] + numList[k];
        if (M - currentSum >= 0 && M - currentMax > M - currentSum)
          currentMax = currentSum;
      }
    }
  }
  std::cout << currentMax << std::endl;
  return 0;
}