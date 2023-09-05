#include <iostream>
#include <queue>
#include <vector>

const int MAX = 1e5 + 5;

int N, M, C;
int result[MAX];
int cnt[MAX] = {
    0,
};
std::vector<std::pair<int, int>> connect[MAX];

void solve() {
  std::queue<int> q;

  for (int i = 1; i <= N; i++) {
    if (!cnt[i])
      q.push(i);
  }

  while (!q.empty()) {
    int elem = q.front();
    q.pop();

    for (int i = 0; i < connect[elem].size(); i++) {
      int connectedElem = connect[elem][i].first;
      int day = connect[elem][i].second;

      if (result[elem] + day > result[connectedElem])
        result[connectedElem] = result[elem] + day;
      if (!--cnt[connectedElem]) {
        q.push(connectedElem);
        // if testcase 2->4: 4, 3->4:4 ? -> 1 6 3 10 (incorrect)
        // if (result[elem] + day > result[connectedElem])
        //   result[connectedElem] = result[elem] + day;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    std::cout << result[i] << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M >> C;
  for (int i = 1; i <= N; i++) {
    std::cin >> result[i];
  }

  int a, b, day;
  for (int i = 0; i < C; i++) {
    std::cin >> a >> b >> day;
    connect[a].push_back({b, day});
    cnt[b]++;
  }

  solve();
  return 0;
}