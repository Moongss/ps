#include <cmath>
#include <iostream>

bool isPrime(int num) {
  if (num == 1) return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int N, M;

  std::cin >> N >> M;
  for (int i = N; i <= M; i++) {
    if (isPrime(i)) std::cout << i << '\n';
  }
  return 0;
}