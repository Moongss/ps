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
  int N, input;
  int sum = 0;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> input;
    if (isPrime(input)) sum++;
  }

  std::cout << sum << std::endl;
  return 0;
}