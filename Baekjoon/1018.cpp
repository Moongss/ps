#include <cmath>
#include <iostream>
#include <string>

#define WHITE 0
#define BLACK 1

char chessColor[2] = {'W', 'B'};
char board[50][50] = {
    0,
};

int getToPaintSquareCount(int x, int y, bool isWhite) {
  int count = 0;
  char mainColor = chessColor[WHITE];
  char subColor = chessColor[BLACK];

  if (!isWhite) {
    mainColor = chessColor[BLACK];
    subColor = chessColor[WHITE];
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i % 2 == 0 && j % 2 == 1 || i % 2 == 1 && j % 2 == 0) {
        if (board[x + i][y + j] != subColor) count++;
      } else {
        if (board[x + i][y + j] != mainColor) count++;
      }
    }
  }

  return count;
}

int main() {
  int N, M;
  int count;
  int min = 64;
  bool isWhite;
  std::string line;

  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    std::cin >> line;
    for (int j = 0; j < M; j++) {
      board[i][j] = line[j];
    }
  }

  for (int x = 0; x <= N - 8; x++) {
    for (int y = 0; y <= M - 8; y++) {
      isWhite = false;
      if (board[x][y] == chessColor[WHITE]) isWhite = true;
      count = getToPaintSquareCount(x, y, isWhite);
      min = (min > count) ? count : min;
      count = getToPaintSquareCount(x, y, !isWhite);
      min = (min > count) ? count : min;
    }
  }

  std::cout << min << std::endl;
  return 0;
}