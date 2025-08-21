#include <algorithm>
#include <iostream>

using namespace std;

bool check[9] = {false};
int save[9];
int input[10] = {0};
int N, M;
int count = 0;

// range : N
// cnt : M
void solve(int currentIndex, int level) {

  int prevNumber = input[currentIndex - 1];
  int prevLevel = level - 1;

  if (level == M) {
    for (int i = 0; i < M; i++) {
      cout << save[i] << " ";
    }
    cout << "\n";
    return;
  }

  // int prevIndex = 0;
  for (int i = currentIndex; i <= N; i++) {

    if (prevNumber < input[i] || (prevNumber == input[i] && prevLevel != level)) {
      save[level] = input[i];
      prevNumber = input[i];
      prevLevel = level;
      solve(i + 1, level + 1);

    }
  }
}

int main() {
  cin >> N >> M;
  input[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> input[i];
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

  solve(1, 0);
}