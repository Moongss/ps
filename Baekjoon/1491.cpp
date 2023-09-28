#include <iostream>

int N, M;
bool arr[5002][5002];

int main() {
    std::cin >> N >> M;

    if (N == M && N == 1) {
        std::cout << "0 0" << std::endl;
        return 0;
    }
    for (int i = 0; i <= M + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            arr[i][j] = false;
        }
    }

    int cnt = 0;
    int x, y;
    x = M, y = 1;
    while (cnt < N * M - 1) {
        while (y < N && !arr[x][y + 1]) {
            arr[x][y++] = true;
            cnt++;
        }
        while (x > 1 && !arr[x - 1][y]) {
            arr[x--][y] = true;
            cnt++;
        }
        while (y > 1 && !arr[x][y - 1]) {
            arr[x][y--] = true;
            cnt++;
        }
        while (x < M && !arr[x + 1][y]) {
            arr[x++][y] = true;
            cnt++;
        }
    }
    x--; y--;
    std::cout << y << " " << (M - 1) - x << std::endl;
    return 0;
}