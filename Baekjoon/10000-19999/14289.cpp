#include <iostream>

#define DIVISOR 1000000007

int N, M, D;
// long long D;
long long arr[50][50] = {
    0,
};
long long result[50][50] = {
    0,
};

void matmul(long long dest[50][50], long long src[50][50]) {

  long long tmp[50][50];
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
  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    result[i][i] = 1;
  }

  int a, b;
  for (int j = 0; j < M; j++) {
    std::cin >> a >> b;
    a -= 1;
    b -= 1;
    arr[a][b] = arr[b][a] = 1;
  }

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