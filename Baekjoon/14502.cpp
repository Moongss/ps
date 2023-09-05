#include <iostream>
#include <queue>
#include <algorithm>

#define EMPTY 0
#define WALL 1
#define VIRUS 2

int N, M;
int arr[8][8];
int tmp[8][8];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int max = 0;

void solve() {
    //find virus
    std::queue<std::pair<int, int> > q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tmp[i][j] = arr[i][j];
            if (tmp[i][j] == VIRUS)
                q.push({i, j});
        }
    }

    while (!q.empty()) {
        std::pair<int, int> coord = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newRow = coord.first + dy[i];
            int newCol = coord.second + dx[i];
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M) {
                if (tmp[newRow][newCol] == EMPTY) {
                    tmp[newRow][newCol] = VIRUS;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         std::cout << tmp[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "\n";


    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == EMPTY)
                cnt++;
        }
    }

    if (max < cnt) max = cnt;
}

void wallSetting(int row, int col, int cnt) {
    if (cnt == 3) {
        solve();
        return;
    }

    for (int i = row; i < N; i++) {
        for (int j = col; j < M; j++) {
            if (arr[i][j] == EMPTY) {
                arr[i][j] = WALL;
                wallSetting(0, 0, cnt + 1);
                arr[i][j] = EMPTY;
            }
        }
    }
}



int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> arr[i][j];
        }
    }

    wallSetting(0, 0, 0);
    std::cout << max << std::endl;    
    return 0;
}