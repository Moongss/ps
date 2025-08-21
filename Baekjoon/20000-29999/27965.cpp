#include <cmath>
#include <iostream>

long long N, K;
long long M = 1;
long long T = 1;
long long result = 0;
int main() {
  std::cin >> N >> K;

  int tmp = N;
  while (tmp / 10 > 0) {
    M++;
    tmp /= 10;
  }

  long long target = (long long)std::pow(10, M - 1);
  while (N) {
    result = (result + (N % K) * (T % K) % K) % K;
    T = ((T % K) * ((long long)std::pow(10, M) % K)) % K;

    if (N == target) {
      M--;
      target /= 10;
    }
    N--;
  }

  std::cout << result << std::endl;
  return 0;
}
