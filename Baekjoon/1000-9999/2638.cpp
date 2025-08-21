#include <iostream>
#include <queue>
#include <cstring>

#define INSIDE_AIR 0
#define CHEESE 1
#define OUTSIDE_AIR 2
#define TO_CHANGE_AIR 3

int N, M;
int arr[102][102];
bool visit[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void printCheese() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void updateAir() {
  std::queue<std::pair<int, int> > airQueue;
  std::pair<int, int> airLocation;

  std::memset(visit, 0, sizeof(visit));

  airQueue.push({1, 1});
  while (!airQueue.empty()) {
    airLocation = airQueue.front();
    airQueue.pop();

    for (int i = 0; i < 4; i++) {
      int row = airLocation.first + dy[i];
      int col = airLocation.second + dx[i];
      if (row >= 1 && row <= N && col >= 1 && col <= M &&
        !visit[row][col] && arr[row][col] != CHEESE) {
        visit[row][col] = true;
        arr[row][col] = OUTSIDE_AIR;
        airQueue.push({row, col});
      }
    }
  }

  // printCheese();
}

int solve(int cheeseCnt) {
  int time = 0;
  int outsideAirCnt = 0;

  while (cheeseCnt > 0) {
    //updateAir
    updateAir();

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (arr[i][j] == CHEESE) {
          outsideAirCnt = 0;
          for (int k = 0; k < 4; k++) {
            if (arr[i + dy[k]][j + dx[k]] == OUTSIDE_AIR)
              outsideAirCnt++;
          }

          if (outsideAirCnt >= 2)
            arr[i][j] = TO_CHANGE_AIR; //queue´ë½Å flag·Î
            // std::cout << "i : " << i << " j : " << j << std::endl;
        }
      }
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (arr[i][j] == TO_CHANGE_AIR) {
          arr[i][j] = OUTSIDE_AIR;
          cheeseCnt--;
        }
      }
    }
    // std::cout << "toRemoveQueue.Size() : " << toRemoveQueue.size() << std::endl;
    // printCheese();
    // std::cout << "====" << std::endl;
    time++;
  }

  return (time);
}

int main() {
  int cheeseCnt = 0;

  std::cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      std::cin >> arr[i][j];
      if (arr[i][j] == CHEESE)
        cheeseCnt++;
    }
  }

  std::cout << solve(cheeseCnt) << std::endl;
  return 0;
}