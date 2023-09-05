#include <iostream>
#include <math.h>

int main() {
  long long n;

  std::cin >> n;
  int target = n % 1500000; //period;

  //m = 1000000, return -> dp[target] % 1000000;
  int test[1500000] = {0};

  test[0] = 0;
  test[1] = 1;

  for (int i = 2; i <= target; i++) {
    test[i] = (test[i - 1] + test[i - 2]) % 1000000;
  }

  std::cout << (test[target]) % 1000000;

  return 0;
}