#include <cmath>
#include <iostream>

long long min, max;

bool isSquareNum[1000001];

int main() {
  std::cin >> min >> max;

  long long N = max - min + 1; // setting
  for (int i = 0; i < N; i++) {
    isSquareNum[i] = false;
  }

  for (long long i = 2; i * i <= max; i++) {
    long long currentSquareNum = i * i;

    long long squareLoop = min / currentSquareNum;
    long long remainder = min % currentSquareNum;
    if (remainder)
      squareLoop++;

    // not s*s! because idx checking.. -> segfault
    for (; squareLoop * i * i <= max; squareLoop++) {
      long long idx = squareLoop * i * i - min;
      isSquareNum[idx] = true;
    }
  }

  int result = 0;
  for (int i = 0; i < N; i++) {
    if (!isSquareNum[i])
      result++;
  }

  std::cout << result << std::endl;
  return 0;
}