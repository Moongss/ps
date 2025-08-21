#include <algorithm>
#include <iostream>
#include <queue>

int map[50][50];
int tmp[50][50];
int R, C, T;
int airCleaner[2];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void clockWiseCleanRoutine() {
  int row = airCleaner[0];
  for (int i = row - 2; i >= 0; i--) {
    tmp[i + 1][0] = tmp[i][0];
  }

  for (int i = 1; i < C; i++) {
    tmp[0][i - 1] = tmp[0][i];
  }

  for (int i = 1; i <= row; i++) {
    tmp[i - 1][C - 1] = tmp[i][C - 1];
  }

  for (int i = C - 2; i >= 1; i--) {
    tmp[row][i + 1] = tmp[row][i];
  }
  tmp[row][1] = 0;
}

void counterClockWiseCleanRoutine() {
  int row = airCleaner[1];
  for (int i = row + 2; i < R; i++) {
    tmp[i - 1][0] = tmp[i][0];
  }

  for (int i = 1; i < C; i++) {
    tmp[R - 1][i - 1] = tmp[R - 1][i];
  }

  for (int i = R - 2; i >= row; i--) {
    tmp[i + 1][C - 1] = tmp[i][C - 1];
  }

  for (int i = C - 2; i >= 1; i--) {
    tmp[row][i + 1] = tmp[row][i];
  }
  tmp[row][1] = 0;
}

void solve() {
  // init
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      tmp[i][j] = 0;
    }
  }
  tmp[airCleaner[0]][0] = -1;
  tmp[airCleaner[1]][0] = -1;

  // spread routine
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (map[i][j] > 0) {
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
          int newRow = i + dx[k];
          int newCol = j + dy[k];
          if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C &&
              map[newRow][newCol] != -1) {
            cnt++;
            tmp[newRow][newCol] += map[i][j] / 5;
          }
        }
        tmp[i][j] += map[i][j] - (map[i][j] / 5) * cnt;
      }
    }
  }

  // clean routine
  clockWiseCleanRoutine();
  counterClockWiseCleanRoutine();

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      map[i][j] = tmp[i][j];
    }
  }
}

int main() {
  std::cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i < R; i++) {
    if (map[i][0] == -1) {
      airCleaner[0] = i;
      airCleaner[1] = i + 1;
      break;
    }
  }

  for (int i = 0; i < T; i++) {
    solve();
  }

  int result = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (map[i][j] > 0)
        result += map[i][j];
    }
  }

  std::cout << result << std::endl;
  return 0;
}