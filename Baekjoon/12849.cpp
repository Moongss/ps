#include <iostream>

#define DIVISOR 1000000007

int N, M, D;
long long arr[8][8] = {
    0,
};
long long result[8][8] = {
    0,
};

void matmul(long long dest[8][8], long long src[8][8]) {

  long long tmp[8][8];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      tmp[i][j] = 0;
      for (int k = 0; k < N; k++) {
        tmp[i][j] += (dest[i][k] * src[k][j]) % DIVISOR;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dest[i][j] = tmp[i][j] % DIVISOR;
    }
  }
}

int main() {

  N = 8;
  for (int i = 0; i < N; i++) {
    result[i][i] = 1;
  }

  arr[0][1] = arr[1][0] = 1;
  arr[0][2] = arr[2][0] = 1;
  arr[1][2] = arr[2][1] = 1;
  arr[1][3] = arr[3][1] = 1;
  arr[2][3] = arr[3][2] = 1;
  arr[2][4] = arr[4][2] = 1;
  arr[3][4] = arr[4][3] = 1;
  arr[3][5] = arr[5][3] = 1;
  arr[4][5] = arr[5][4] = 1;
  arr[4][6] = arr[6][4] = 1;
  arr[5][7] = arr[7][5] = 1;
  arr[6][7] = arr[7][6] = 1;

  std::cin >> D;
  while (D > 0) {
    // result = arr * arr (arr^2)
    if (D % 2 == 1) {
      matmul(result, arr);
    }
    // result = result * arr
    matmul(arr, arr);
    D /= 2;
  }

  std::cout << result[0][0] << std::endl;
  return 0;
}