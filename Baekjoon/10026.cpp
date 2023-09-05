#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

#define RED 'R'
#define GREEN 'G'
#define BLUE 'B'

//Red-Green Color Blindness

int N;
char painting[102][102] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool isVisited[102][102] = {0, };

void dfs(int row, int col, bool isBlindness) {
    std::pair<int, int>colorCoordinate;
    std::queue<std::pair<int, int> >colorQueue;

    char targetColor = painting[row][col];
    colorQueue.push({row, col});

    while (!colorQueue.empty()) {
        colorCoordinate = colorQueue.front();
        colorQueue.pop();

        int currentRow = colorCoordinate.first;
        int currentCol = colorCoordinate.second;
        for (int i = 0; i < 4; i++) {
            if (!isVisited[currentRow + dy[i]][currentCol + dx[i]]) {
                char aroundColor = painting[currentRow + dy[i]][currentCol + dx[i]];
                if (aroundColor == targetColor) {
                    isVisited[currentRow + dy[i]][currentCol + dx[i]] = true;
                    colorQueue.push({currentRow + dy[i], currentCol + dx[i]});
                }
                else if (isBlindness &&
                    (aroundColor == GREEN && targetColor == RED ||
                    aroundColor == RED && targetColor == GREEN)) {
                    isVisited[currentRow + dy[i]][currentCol + dx[i]] = true;
                    colorQueue.push({currentRow + dy[i], currentCol + dx[i]});
                }
            }
        }
    }
}
void printVisited() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cout << isVisited[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void printPrinting() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cout << painting[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int solve(bool isBlindness) {
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!isVisited[i][j]) {
                isVisited[i][j] = true;
                dfs(i, j, isBlindness);
                cnt++;
            }
        }
    }

    return cnt;
}

void initPainting() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> painting[i][j];
        }
    }
}

int main() {
    std::cin >> N;    

    initPainting();
    int commonAreaNum = 0;
    int RedGreenColorBlindnessAreaNum = 0;

    commonAreaNum = solve(false);
    memset(isVisited, 0, sizeof(isVisited));
    RedGreenColorBlindnessAreaNum = solve(true);

    std::cout << commonAreaNum << " " << RedGreenColorBlindnessAreaNum << std::endl;
    return 0;
}