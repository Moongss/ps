#include <cstring>
#include <iostream>

int N;
int SCV[61][61][61];
int HP[3] = {
    0,
};

int cnt = 0;
int min(int a, int b) { return (a < b) ? a : b; }
int solve(int a, int b, int c) {
  cnt++;
  if (a < 0) // if use solve(0, b, c), time over?
    a = 0;
  if (b < 0)
    b = 0;
  if (c < 0)
    c = 0;

  if (a == 0 && b == 0 && c == 0)
    return 0;

  int &result = SCV[a][b][c];

  if (result != -1)
    return result;

  result = 42424242; // not calculate
  result = min(result, solve(a - 9, b - 1, c - 3) + 1);
  result = min(result, solve(a - 9, b - 3, c - 1) + 1);
  result = min(result, solve(a - 1, b - 9, c - 3) + 1);
  result = min(result, solve(a - 3, b - 9, c - 1) + 1);
  result = min(result, solve(a - 1, b - 3, c - 9) + 1);
  result = min(result, solve(a - 3, b - 1, c - 9) + 1);
  return result;
}

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> HP[i];
  }

  std::memset(SCV, -1, sizeof(SCV));
  std::cout << solve(HP[0], HP[1], HP[2]) << std::endl;
  // std::cout << "[DEBUG] cnt : " << cnt << std::endl;
  return 0;
}
