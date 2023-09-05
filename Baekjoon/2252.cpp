#include <iostream>
#include <stack>
#include <vector>

int N, M;
std::vector<int> info[32001];
int connect[32001] = {
    0,
};

void topologySort() {
  std::stack<int> q;
  for (int i = 1; i <= N; i++) {
    if (connect[i] == 0) {
      q.push(i);
    }
  }

  int result[32001];
  for (int i = 1; i <= N; i++) {
    if (q.empty())
      break;

    int x = q.top();
    q.pop();
    result[i] = x;

    for (int i = 0; i < info[x].size(); i++) {
      connect[info[x][i]]--;
      if (connect[info[x][i]] == 0)
        q.push(info[x][i]);
    }
  }

  for (int i = 1; i <= N; i++) {
    std::cout << result[i] << " ";
  }
}

int main() {

  int start, dest;
  std::cin >> N >> M;

  for (int i = 0; i < M; i++) {
    std::cin >> start >> dest;
    info[start].push_back(dest);
    connect[dest]++;
  }
  topologySort();
  return 0;
}