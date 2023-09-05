#include <algorithm>
#include <cstring>
#include <iostream>

int N, M;
int map[502][502];
int dp[502][502];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solve(int x, int y) {

  // std::cout << "x : " << x << ", y : " << y << std::endl;
  // std::cout << "dp[x][y] : " << dp[x][y] << std::endl;

  if (x == M && y == N)
    return 1;
  if (dp[x][y] != -1)
    return dp[x][y];

  dp[x][y] = 0;

  for (int i = 0; i < 4; i++) {
    int newX = x + dx[i];
    int newY = y + dy[i];

    if (map[newX][newY] && map[x][y] > map[newX][newY]) {
      dp[x][y] += solve(newX, newY);
    }
  }

  return dp[x][y];
}

void init() {
  int height;
  std::cin >> M >> N;
  memset(map, 0, sizeof(map));
  memset(dp, -1, sizeof(dp));

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> height;
      map[i][j] = height;
    }
  }
}

int main() {
  init();
  std::cout << solve(1, 1) << std::endl;
  return 0;
}