#include <iostream>

int main() {
  int n;
  int max = -1;
  int score[1000] = {0};

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> score[i];
    if (max < score[i]) max = score[i];
  }

  double sum = 0.0f;
  for (int i = 0; i < n; i++) {
    sum += (double) score[i] / (max * 1.0f) * 100;
  }

  std::cout << std::fixed;
  std::cout.precision(9);
  std::cout << sum / n;
}