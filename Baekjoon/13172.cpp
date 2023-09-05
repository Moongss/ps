#include <iostream>

#define MOD 1000000007

//b^-1 = b^(x-2)
long long pow(long long b, long long x) {
  long long result = 1;

  while (x) {
    if (x & 1)
      result = result % MOD * b % MOD;
    b = (b * b) % MOD;
    x >>= 1;
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int M;
  int a, b;
  long long result = 0;
  
  std::cin >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> b >> a;

    result += (a * pow(b, MOD - 2)) % MOD;
    result %= MOD;
  }

  std::cout << result << "\n";
  return 0;
}
