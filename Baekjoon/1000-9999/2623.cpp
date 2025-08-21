#include <iostream>
#include <queue>

int N;
int PD;

int cnt[1001];
std::vector<int> connected[1001];
std::queue<int> q;
std::queue<int> result;

bool isPossible() {
  for (int i = 1; i <= N; i++) {
    if (!cnt[i])
      q.push(i);
  }

  while (!q.empty()) {
    int elem = q.front();
    q.pop();

    result.push(elem);
    for (int i = 0; i < connected[elem].size(); i++) {
      if (!--cnt[connected[elem][i]])
        q.push(connected[elem][i]);
    }
  }

  for (int i = 0; i < N; i++) {
    if (cnt[i] != 0)
      return false;
  }
  return true;
}
int main() {
  std::cin >> N >> PD;

  for (int i = 0; i < PD; i++) {
    int M, cur, next;

    std::cin >> M;
    cur = -1;
    for (int j = 0; j < M; j++) {
      if (j == 0) {
        std::cin >> cur;
        continue;
      }
      std::cin >> next;
      cnt[next]++;
      connected[cur].push_back(next);
      cur = next;
    }
  }

  if (isPossible()) {
    while (!result.empty()) {
      std::cout << result.front() << std::endl;
      result.pop();
    }
  } else {
    std::cout << 0 << std::endl;
  }
  return 0;
}