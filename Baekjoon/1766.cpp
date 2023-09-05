#include <iostream>
#include <queue>
#include <vector>

int N, M;
int in[32001] = {
    0,
};
std::vector<int> connect[32001];

void solve() {
  std::priority_queue<int> pq;

  for (int i = 1; i <= N; i++) {
    if (!in[i])
      pq.push(-i);
  }

  while (!pq.empty()) {
    int v = -pq.top();
    std::cout << v << " ";
    pq.pop();

    for (int i = 0; i < connect[v].size(); i++) {
      if (!--in[connect[v][i]])
        pq.push(-connect[v][i]);
    }
  }
  std::cout << std::endl;
}

int main() {
  int x, y;

  std::cin >> N >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> x >> y;
    connect[x].push_back(y);
    in[y]++;
  }

  solve();
  return 0;
}