#include <iostream>
#include <string>

std::string PUZZLE = "ABCDEFGHIJKLMNO.";

char board[4][4];
int result = 0;

int main() {
  for (int i = 0; i < 16; i++) {
    if (i % 4 == 0 && i)
      getchar();
    scanf("%c", &board[i / 4][i % 4]);
  }

  for (int i = 0; i < 16; i++) {
    if (board[i / 4][i % 4] != PUZZLE[i]) {
      if (PUZZLE[i] == '.')
        continue;

      int tmp = 0;
      while (board[tmp / 4][tmp % 4] != PUZZLE[i])
        tmp++;
      result += std::abs(tmp / 4 - i / 4) + std::abs(tmp % 4 - i % 4);
    }
  }

  std::cout << result << std::endl;
  return 0;
}