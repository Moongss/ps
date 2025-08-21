#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

std::pair<int, int> start, end;
std::queue<std::pair<int, int>> water;

int R, C;
char map[50][50];

int move[50][50];
bool visit[50][50];

int flow[50][50];

void waterSetting() {
  std::pair<int, int> elem;

  while (!water.empty()) {
    elem = water.front();
    water.pop();

    for (int i = 0; i < 4; i++) {
      int newX = elem.first + dx[i];
      int newY = elem.second + dy[i];
      if (newX < 0 || newX > R || newY < 0 || newY > C)
        continue;
      if (map[newX][newY] != '.')
        continue;
      if (flow[elem.first][elem.second] + 1 < flow[newX][newY]) {
        flow[newX][newY] = flow[elem.first][elem.second] + 1;
        water.push({newX, newY});
      }
    }
  }
}

int main() {
  std::cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      flow[i][j] = 42424242;
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> map[i][j];
      if (map[i][j] == 'S')
        start = {i, j};
      if (map[i][j] == 'D')
        end = {i, j};
      if (map[i][j] == '*') {
        water.push({i, j});
        flow[i][j] = 0;
      }
    }
  }

  waterSetting();
  std::queue<std::pair<int, int>> q;
  visit[start.first][start.second] = true;
  q.push(start);

  while (!q.empty()) {
    std::pair<int, int> elem = q.front();
    q.pop();

    if (elem == end) {
      std::cout << move[end.first][end.second] << std::endl;
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int newX = elem.first + dx[i];
      int newY = elem.second + dy[i];
      int nextMove = move[elem.first][elem.second] + 1;
      if (newX < 0 || newX > R || newY < 0 || newY > C)
        continue;
      if (visit[newX][newY])
        continue;
      if (map[newX][newY] == 'X')
        continue;

      if (nextMove)
      if (nextMove >= flow[newX][newY])
        continue;
      visit[newX][newY] = true;
      move[newX][newY] = nextMove;
      q.push({newX, newY});
    }
  }
  std::cout << "KAKTUS";
  return 0;
}