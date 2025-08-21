#include <cstring>
#include <iostream>

bool isVisited[100001];
bool isFinished[100001]; // 2개로 잡는건 생각했음
int selected[100001];
int N, T;
int result;

void solve(int elem) {
  isVisited[elem] = true;

  int next = selected[elem];
  if (!isVisited[next]) {
    solve(next);
  } else if (!isFinished[next]) {
    //아래처럼 for문으로 돌리는 아이디어를 못냄..
    result--;
    for (int i = next; i != elem && !isFinished[next]; i = selected[i])
      result--;
  }
  isFinished[elem] = true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> T;

  for (int i = 0; i < T; i++) {
    memset(isVisited, 0, sizeof(isVisited));
    memset(isFinished, 0, sizeof(isFinished));
    std::cin >> N;
    result = N;
    for (int j = 1; j <= N; j++) {
      std::cin >> selected[j];
    }

    for (int j = 1; j <= N; j++) {
      if (!isVisited[j])
        solve(j);
    }

    std::cout << result << "\n";
  }
  return 0;
}