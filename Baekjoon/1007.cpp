#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define X_IDX 0
#define Y_IDX 1
#define MAX 424242

int T, N;
int inputTotal[2];
double result;
bool comb[20] = {false, };
std::vector<std::pair<int, int>> input;

double getMinVector() {
  std::pair<int, int> a, b;

  int xTotal, yTotal;
  xTotal = yTotal = 0;

  for (int i = 0; i < N; i++) {
    if (comb[i]) {
      xTotal += input[i].first;
      yTotal += input[i].second;
    }
  }

  double tmp = sqrt(pow((inputTotal[X_IDX] - xTotal * 2), 2.0f) +
                    pow((inputTotal[Y_IDX] - yTotal * 2), 2.0f));

  if (tmp < result)
    result = tmp;
  return result;
}

void solve(int start, int cnt) {
  double tmp;

  if (cnt == N / 2) {
    tmp = getMinVector();
    if (tmp < result)
      result = tmp;
    return;
  }

  if (start >= N)
    return;

  comb[start] = true;
  solve(start + 1, ++cnt);
  comb[start] = false;
  solve(start + 1, --cnt);
}

void init() {
  result = MAX;
  inputTotal[X_IDX] = inputTotal[Y_IDX] = 0;
  input.clear();
}

int main() {
  std::cin.tie(0);
  std::cout.tie(0);
  std::ios_base::sync_with_stdio(false);
  int x, y;

  std::cin >> T;
  for (int i = 0; i < T; i++) {
    init();
    std::cin >> N;
    for (int j = 0; j < N; j++) {
      std::cin >> x >> y;
      inputTotal[X_IDX] += x;
      inputTotal[Y_IDX] += y;
      input.push_back({x, y});
    }
    solve(1, 0);
    std::cout << std::fixed;
    std::cout.precision(12);
    std::cout << result << std::endl;
  }

  return 0;
}
