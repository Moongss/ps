#include <algorithm>
#include <iostream>
#include <queue>

int N, M;
int map[1000][1000];
int result[1000][1000];
bool visit[1000][1000];
std::pair<int, int> start;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    std::queue<std::pair<int, int>> q;

    q.push(start);
    visit[start.first][start.second] = true;
    result[start.first][start.second] = 0;
    while (!q.empty()) {

        std::pair<int, int> elem = q.front();
        q.pop();
    
        int x = elem.first;
        int y = elem.second;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newX >= N || newY < 0 || newY >= M)
                continue;
            if (visit[newX][newY])
                continue;
            if (map[newX][newY] == 0) {
                result[newX][newY] = 0;
                continue;
            }

            visit[newX][newY] = true;
            result[newX][newY] = result[x][y] + 1;
            q.push({newX, newY});
        }
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            result[i][j] = -1;
            if (map[i][j] == 0)
                result[i][j] = 0;
            if (map[i][j] == 2)
                start = {i, j};
        }
    }

    // bfs ÂßÂß
    solve();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}