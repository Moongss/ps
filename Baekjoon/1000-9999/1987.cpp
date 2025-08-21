#include <iostream>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char map[20][20];
int R, C;
int result = 0;
bool visited[26] = {false, };

void solve(int x, int y, int cnt) {
    if (cnt > result)
        result = cnt;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < R && newY >= 0 && newY < C 
            && !visited[map[newX][newY] - 'A']) {
            visited[map[newX][newY] - 'A'] = true;
            solve(newX, newY, cnt + 1);
            visited[map[newX][newY] - 'A'] = false;
        }
    }
}

int main() {
    std::cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> map[i][j];
        }
    }

    visited[map[0][0] - 'A'] = true;
    solve(0, 0, 1);
    std::cout << result << std::endl;
    return 0;
}