#include <iostream>
#include <queue>
#include <vector>

#define ROAD 0
#define WALL 1
#define INF 42424242

int N, M;
int arr[1000][1000];
int visit[1000][1000][2] = {0, };

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};


int getMinDistance() {
  std::queue<std::pair<std::pair<int, int>, int> > coordQueue;
  coordQueue.push({{0, 0}, 0});

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     visit[i][j] = 0;
  //   }
  // }

  visit[0][0][0] = 1;
  while (!coordQueue.empty()) {
    std::pair<int, int> coord = coordQueue.front().first;
    int isBreakWall = coordQueue.front().second;
    coordQueue.pop();

    if (coord.first == N - 1 && coord.second == M - 1)
      return (visit[N - 1][M - 1][isBreakWall]);

    
    for (int i = 0; i < 4; i++) {
      int row = coord.first + dy[i];
      int col = coord.second + dx[i];
      
      if (row >= 0 && row < N && col >= 0 && col < M) {
        if (!visit[row][col][isBreakWall]) {
          if (arr[row][col] == ROAD) { // 0 -> 0, // 0 -> 1 -> 0?
            visit[row][col][isBreakWall] = visit[coord.first][coord.second][isBreakWall] + 1;
            coordQueue.push({{row, col}, isBreakWall});
          }
          if (arr[row][col] == WALL && isBreakWall == false) {
            visit[row][col][true] = visit[coord.first][coord.second][false] + 1;
            coordQueue.push({{row, col}, true});
          }
        }
      }
    }
  }
  return (-1);
}

int main() {  
  std::vector<std::pair<int, int> > wallVector;
  
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     if (arr[i][j] == WALL) {
  //       int cnt = 0;
  //       for (int k = 0; k < 4; k++) {
  //         int row = i + dy[k];
  //         int col = j + dx[k];
  //         if (row >= 0 && row < N && col >= 0 && col < N 
  //             && arr[row][col] == ROAD)
  //             cnt++;
  //       }
  //       if (cnt >= 2)
  //         wallVector.push_back({i, j});
  //     }
  //   }
  // }

  std::cout << getMinDistance() << std::endl;
  // for (int i = 0; i < wallVector.size(); i++) {
  //   std::pair<int, int> tmp = wallVector[i];
  //   arr[tmp.first][tmp.second] = ROAD;

  //   int distance = getMinDistance();
  //   if (distance < result && distance > 0)
  //     result = distance;
    
  //   arr[tmp.first][tmp.second] = WALL;
  // }

  return 0;
}