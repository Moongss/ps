#include <string.h>

#include <iostream>

int arr[50][50] = {0};
bool visited[50][50] = {false};
int sum = 0;
int M, N;

void check(int y, int x, bool isNew) {
  if (x >= 0 && x < M && y >= 0 && y < N && arr[y][x] == 1 && !visited[y][x]) {
    if (isNew) sum++;

    visited[y][x] = true;
    if (y + 1 < N) check(y + 1, x, false);
    if (y - 1 >= 0) check(y - 1, x, false);
    if (x - 1 >= 0) check(y, x - 1, false);
    if (x + 1 < M) check(y, x + 1, false);
  }
}

int main() {
  int T, K;
  int x, y;
  bool flag = false;

  std::cin >> T;
  for (int i = 0; i < T; i++) {
    // map clear
    sum = 0;
    memset(visited, 0, sizeof(visited));
    memset(arr, 0, sizeof(arr));

    // map initialize
    std::cin >> M >> N >> K;
    for (int j = 0; j < K; j++) {
      std::cin >> x >> y;  // col, row
      arr[y][x] = 1;
    }

    for (int a = 0; a < N; a++) {    // N = 세로길이
      for (int b = 0; b < M; b++) {  // M = 가로길이..
        check(a, b, true);
      }
    }

    std::cout << sum << '\n';
  }
  return 0;
}