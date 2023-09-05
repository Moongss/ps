#include <iostream>

using namespace std;

bool check[9] = {false};
char save[9];
char input[15] = {0};
int N, M;

// range : N
// cnt : M

bool isSuitablePassword() {
    char vowelList[5] = {'a', 'e', 'i', 'o', 'u'};
    int vowelCnt = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            if (save[i] == vowelList[j])
                vowelCnt++;
        }
    }

    return (vowelCnt >= 1 && (M - vowelCnt) >= 2);
}

void solve(int currentIndex, int level) {

  int prevNumber = input[currentIndex - 1];
  int prevLevel = level - 1;

  if (level == M && isSuitablePassword()) {
    for (int i = 0; i < M; i++) {
      cout << save[i];
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
  cin >> M >> N;
  for (int i = 1; i <= N; i++) {
    cin >> input[i];
  }

  // sort input data.
  char tmp;
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