#include <iostream>

int map[17][17];

#define HORIZONTAL 1
#define VERTICAL 2
#define DIAGONAL 3
//(1, 2) to (N, N)

#define EMPTY 0
#define WALL 1

int N;
int result = 0;

void solve(int row, int col, int type) {

  if (row == N && col == N) {
    result++;
    return;
  }

  //가로, 대각선 -> 가로
  if (type == HORIZONTAL || type == DIAGONAL) {
    if (col + 1 <= N && map[row][col + 1] == EMPTY)
      solve(row, col + 1, HORIZONTAL);
  }

  //세로, 대각선 -> 세로
  if (type == VERTICAL || type == DIAGONAL) {
    if (row + 1 <= N && map[row + 1][col] == EMPTY)
      solve(row + 1, col, VERTICAL);
  }

  //가로, 세로, 대각선 -> 대각선
  if (row + 1 <= N && col + 1 <= N 
    && map[row + 1][col + 1] == EMPTY && map[row][col + 1] == EMPTY
    && map[row + 1][col] == EMPTY)
    solve(row + 1, col + 1, DIAGONAL);
}

int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> map[i][j];
    }
  }

  solve(1, 2, HORIZONTAL);
  std::cout << result << std::endl;
  
  return 0;
}