#include <iostream>

int result[9][9] = {
    0,
};

int input[9][9];

bool checkHorizontalLine(int x, int y) {
  for (int i = 0; i < 9; i++) {
    if (i != y && result[x][i] == result[x][y])
      return false;
  }
  return true;
}

bool checkVerticalLine(int x, int y) {
  for (int i = 0; i < 9; i++) {
    if (i != x && result[i][y] == result[x][y])
      return false;
  }
  return true;
}

bool checkSquare(int x, int y) {
  for (int i = (x / 3) * 3; i <= (x / 3) * 3 + 2; i++) {
    for (int j = (y / 3) * 3; j <= (y / 3) * 3 + 2; j++) {
      // std::cout << "i, j : " << i << ", " << j << std::endl;
      if (i != x && j != y && result[i][j] == result[x][y])
        return false;
    }
  }
  return true;
}

bool isValid(int x, int y) {
  if (!checkHorizontalLine(x, y)) {
    return false;
  }
  if (!checkVerticalLine(x, y)) {
    return false;
  }

  if (!checkSquare(x, y)) {
    return false;
  }

  return true;
}

void solve(int idx) {
  if (idx == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        std::cout << result[i][j] << " ";
      }
      std::cout << std::endl;
    }
    exit(0);
  }

  int x = idx / 9;
  int y = idx % 9;

  if (input[x][y] != 0) {
    solve(idx + 1);
  } else {
    for (int num = 1; num <= 9; num++) {
      result[x][y] = num; //³Ö°í,, »©ÀÚ?
      if (isValid(x, y))
        solve(idx + 1);
      result[x][y] = 0;
    }
  }
}

int main() {

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%1d", &input[i][j]);
      result[i][j] = input[i][j];
    }
  }

  solve(0);
  return 0;
}