#include <iostream>
#include <queue>
#include <vector>

int N;
bool visit[1001] = {
    false,
};
std::vector<std::pair<int, int>> connect[1001];

long solve(int start) {
  long result = 0;
  std::priority_queue<std::pair<int, int>> q;

  for (int i = 0; i < connect[start].size(); i++) {
    int node = connect[start][i].first;
    int weight = connect[start][i].second;

    q.push({-weight, node});
  }

  while (!q.empty()) {
    std::pair<int, int> elem = q.top();
    q.pop();

    int weight = -elem.first;
    int node = elem.second;

    if (visit[node])
      continue;
    visit[node] = true;
    result += weight;
    for (int i = 0; i < connect[node].size(); i++) {
      if (!visit[connect[node][i].first])
        q.push({-connect[node][i].second, connect[node][i].first});
    }
  }

  return result;
}

int main() {
  int weight;
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> weight;
      connect[i].push_back({j, weight});
      connect[j].push_back({i, weight});
    }
  }

  std::cout << solve(1) << std::endl;
  return 0;
}