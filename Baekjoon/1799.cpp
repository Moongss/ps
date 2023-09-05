#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

#define IMPOSSIBLE 0
#define POSSIBLE 1

#define BLACK 0
#define WHITE 1
int N;
int map[11][11] = {
    0,
};
bool check[11][11] = {
    0,
};

std::vector<std::pair<int, int>> possibleArea;
int possibleAreaSize = 0;
int blackBishopCnt = 0;
int whiteBishopCnt = 0;

bool isPossible(int targetIdx) {
  std::pair<int, int> targetArea = possibleArea[targetIdx];
  int x, y;

  x = targetArea.first - 1;
  y = targetArea.second - 1;
  while (x >= 1 && x <= N && y >= 1 && y <= N) {
    if (check[x][y])
      return false;
    x--;
    y--;
  }

  x = targetArea.first - 1;
  y = targetArea.second + 1;
  while (x >= 1 && x <= N && y >= 1 && y <= N) {
    if (check[x][y])
      return false;
    x--;
    y++;
  }

  return true;
}

void solve(int idx, int cnt, int flag) {
  if (flag == BLACK && blackBishopCnt < cnt)
    blackBishopCnt = cnt;
  if (flag == WHITE && whiteBishopCnt < cnt)
    whiteBishopCnt = cnt;

  for (int i = idx; i < possibleAreaSize; i++) {
    std::pair<int, int> elem = possibleArea[i];

    if (flag == BLACK) {
      if (elem.first % 2 == 1 && elem.second % 2 == 0)
        continue;
      if (elem.first % 2 == 0 && elem.second % 2 == 1)
        continue;
    }
    if (flag == WHITE) {
      if (elem.first % 2 == 1 && elem.second % 2 == 1)
        continue;
      if (elem.first % 2 == 0 && elem.second % 2 == 0)
        continue;
    }

    if (isPossible(i)) {
      check[elem.first][elem.second] = true;
      // std::cout << "possibleCoord : " << elem.first << ", " << elem.second
      //           << std::endl;
      solve(i + 1, cnt + 1, flag);
      check[elem.first][elem.second] = false;
    }
  }
}

void init() {
  int info;

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> map[i][j];
      check[i][j] = false;
      if (map[i][j] == POSSIBLE) {
        possibleArea.push_back({i, j});
        possibleAreaSize++;
      }
    }
  }
}

int main() {

  init();
  solve(0, 0, BLACK);
  solve(0, 0, WHITE);
  std::cout << blackBishopCnt + whiteBishopCnt << std::endl;
  return 0;
}
