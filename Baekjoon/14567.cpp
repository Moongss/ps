#include <iostream>
#include <queue>
#include <vector>

std::vector<int> subject[1001];
int cnt[1001] = {
    0,
};
int result[1001] = {
    0,
};
int N, M;

void solve() {
  std::queue<int> q;

  for (int i = 1; i <= N; i++) {
    if (cnt[i] == 0) {
      result[i]++;
      q.push(i);
    }
  }

  while (!q.empty()) {
    int elem = q.front();
    q.pop();

    for (int i = 0; i < subject[elem].size(); i++) {
      int connectedElem = subject[elem][i];
      if (!--cnt[connectedElem]) {
        result[connectedElem] = result[elem] + 1;
        q.push(connectedElem);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int a, b;
  std::cin >> N >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> a >> b;
    subject[a].push_back(b);
    cnt[b]++;
  }

  solve();
  return 0;
}