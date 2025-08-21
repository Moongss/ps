#include <algorithm>
#include <iostream>

bool check[9] = {false};
int save[9];
int input[10] = {0};
int N, M;

// range : N
// cnt : M
void solve(int level) {

  int prevNumber = input[0];

  if (level == M) {
    for (int i = 0; i < M; i++) {
      std::cout << save[i] << " ";
    }
    std::cout << "\n";
    return;
  }

  // int prevIndex = 0;
  for (int i = 0; i <= N; i++) {
    if (prevNumber == input[i])
      continue;
    save[level] = input[i];
    prevNumber = input[i];
    solve(level + 1);
  }
}

int main() {
  std::cin >> N >> M;
  input[0] = 0;

  for (int i = 1; i <= N; i++) {
    std::cin >> input[i];
  }

  // sort input data.
  int tmp;
  for (int i = 1; i <= N - 1; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (input[i] > input[j]) {
        tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
      }
    }
  }

  solve(0);
}