#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> node[1001];
bool isVisited[1001];

void dfs(int point) {
  if (isVisited[point])
    return;
  
  isVisited[point] = true;
  for (int i = 0; i < node[point].size(); i++) {
    if (!isVisited[node[point][i]])
      dfs(node[point][i]);
  }
}

int main() {
  int N, M, u, v;

  std::cin >> N >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    node[u].push_back(v);
    node[v].push_back(u);
  }  

  for (int i = 1; i <= N; i++) {
    std::sort(node[i].begin(), node[i].end());
    isVisited[i] = false;
  }

  int sum = 0;
  for (int i = 1; i <= N; i++) {
    if (!isVisited[i]) {
      dfs(i);
      sum++;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}