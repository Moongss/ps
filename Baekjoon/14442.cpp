#include <iostream>
#include <queue>
#include <vector>

#define ROAD 0
#define WALL 1
#define INF 42424242

int N, M, maxBreakWall;
int arr[1000][1000];
int visit[1000][1000][10] = {
    0,
};

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int result = INF;
int getMinDistance() {
  std::queue<std::pair<std::pair<int, int>, int>> coordQueue;
  coordQueue.push({{0, 0}, 0});

  visit[0][0][0] = 1;
  while (!coordQueue.empty()) {
    std::pair<int, int> coord = coordQueue.front().first;
    int isBreakWall = coordQueue.front().second;
    coordQueue.pop();

    // BFS라 먼저 도착한게 젤 빠른거 아닌가?
    if (coord.first == N - 1 && coord.second == M - 1) {
      // std::cout << "isBreakWall : " << isBreakWall << std::endl;
      // for (int i = 0; i < N; i++) {
      //   for (int j = 0; j < M; j++) {
      //     std::cout << visit[i][j][isBreakWall];
      //   }
      //   std::cout << std::endl;
      // }
      return (visit[N - 1][M - 1][isBreakWall]);
    }

    for (int i = 0; i < 4; i++) {
      int row = coord.first + dy[i];
      int col = coord.second + dx[i];

      if (row >= 0 && row < N && col >= 0 && col < M) {
        if (arr[row][col] == ROAD && !visit[row][col][isBreakWall]) {
          visit[row][col][isBreakWall] =
              visit[coord.first][coord.second][isBreakWall] + 1;
          coordQueue.push({{row, col}, isBreakWall});
        } else if (arr[row][col] == WALL && isBreakWall < maxBreakWall &&
                   !visit[row][col][isBreakWall + 1]) {
          visit[row][col][isBreakWall + 1] =
              visit[coord.first][coord.second][isBreakWall] + 1;
          coordQueue.push({{row, col}, isBreakWall + 1});
        }
      }
    }
  }
  return (-1);
}

int main() {
  std::vector<std::pair<int, int>> wallVector;

  scanf("%d %d %d", &N, &M, &maxBreakWall);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }

  std::cout << getMinDistance() << std::endl;
  return 0;
}