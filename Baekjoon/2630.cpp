#include <iostream>

#define WHITE 0
#define BLUE 1

int colorSpace[128][128];
int colorPaperCnt[2];

void solve(int row, int col, int N) {
    int currentColor = colorSpace[row][col];
    bool isSameColor = true;

    for (int i = row; i < row + N; i++) {
        for (int j = col; j < col + N; j++) {
            if (currentColor != colorSpace[i][j]) {
                isSameColor = false;
                break;
            }
        }
    }

    if (!isSameColor) {
        solve(row, col, N / 2);
        solve(row + N / 2, col, N / 2);
        solve(row, col + N / 2, N / 2);
        solve(row + N / 2, col + N / 2, N / 2);
    } else if (currentColor == WHITE) {
        colorPaperCnt[WHITE]++;
    } else {
        colorPaperCnt[BLUE]++;
    }
};

int main() {
    int N, color;
    
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> color;
            colorSpace[i][j] = color;
        }
    }

    colorPaperCnt[WHITE] = 0;
    colorPaperCnt[BLUE] = 0;
    solve(0, 0, N);

    std::cout << colorPaperCnt[WHITE] << "\n" << colorPaperCnt[BLUE] << std::endl;
}