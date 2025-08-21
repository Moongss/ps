#include <iostream>
#include <queue>
#include <vector>

int T, N, K;

int w[1001] = {0, };
int in[1001] = {0, };
int dp[1001] = {0, };
std::vector<int> connect[1001];

int max(int a, int b) { return (a > b ? a : b); }
void solve() {
  std::queue<int> q;

  for (int i = 1; i <= N; i++) {
    if (in[i] == 0) {
      q.push(i);
      dp[i] = w[i];
    }
  }

  while (!q.empty()) {
    int elem = q.front();
    q.pop();
    for (int i = 0; i < connect[elem].size(); i++) {
      dp[connect[elem][i]] = max(dp[connect[elem][i]], dp[elem] + w[connect[elem][i]]);
      if (!--in[connect[elem][i]]) {
        // std::cout << "elem : " << elem << std::endl;
        // std::cout << "connect[elem][i] : " << connect[elem][i] << std::endl;
        // std::cout << "dp[connect[elem][i]] : " << dp[connect[elem][i]] << std::endl;
        // std::cout << "dp[elem] : " << dp[elem] << std::endl;
        // std::cout << "w[connect[elem][i]] : " << w[connect[elem][i]] << std::endl;
        // std::cout << "result : " << dp[connect[elem][i]] << std::endl << std::endl;
        q.push(connect[elem][i]);
      }
    }
  }
}

void init() {
  for (int i = 0; i < 1001; i++) {
    dp[i] = -1;
    w[i] = in[i] = 0;
    connect[i].clear();
  }
}

int main() {
  int x, y, target;
  std::cin >> T;
  for (int i = 0; i < T; i++) {
    init();
    std::cin >> N >> K;
    for (int j = 1; j <= N; j++)
      std::cin >> w[j];
    for (int j = 1; j <= K; j++) {
      std::cin >> x >> y;
      connect[x].push_back(y);
      in[y]++;
    }
    solve();
    std::cin >> target;
    std::cout << dp[target] << std::endl;
  }
  return 0;
}