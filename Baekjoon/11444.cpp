#include <iostream>

#define DIVISOR 1000000007
long long result[2][2] = {{1, 0}, {0, 1}}; // I
long long A[2][2] = {{1, 1}, {1, 0}}; //Target Matrix?

void matmul(long long dest[2][2], long long src[2][2]) {
  long long tmp[2][2];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tmp[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        tmp[i][j] += ((dest[i][k] % DIVISOR) * (src[k][j] % DIVISOR)) % DIVISOR; 
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      dest[i][j] = tmp[i][j] % DIVISOR;
    }
  }
}

int main() {
  long long n;

  std::cin >> n;
  while (n != 0) {
    if (n & 1)
      matmul(result, A);
    matmul(A, A);
    n >>= 1;
  }

  std::cout << result[1][0] % DIVISOR << std::endl;
  return 0;
}