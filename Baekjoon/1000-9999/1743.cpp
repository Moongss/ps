#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M, K;
std::queue<std::pair<int, int> > trashQueue;
bool visit[101][101];
int map[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    std::cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y;
        std::cin >> x >> y;
        map[x][y] = 1;
        trashQueue.push(std::make_pair(x, y));
    }

    std::queue<std::pair<int, int>> q;
    int result = -1;
    while (!trashQueue.empty()) {

        q.push(trashQueue.front());
        trashQueue.pop();
        
        visit[q.front().first][q.front().second] = true;
        int tmp = 0;
        while (!q.empty()) {
            std::pair<int, int> elem = q.front();
            q.pop();

            // if ( visit[elem.first][elem.second] == true)
            //     continue;
            tmp++;

            for (int i = 0; i < 4; i++) {
                int newX = elem.first + dx[i];
                int newY = elem.second + dy[i];
                if (newX < 1 || newX > 100 || newY < 1 || newY > 100)
                    continue;
                if (visit[newX][newY])
                    continue;
                if (map[newX][newY] == 0)
                    continue;

                visit[newX][newY] = true;
                q.push(std::make_pair(newX, newY));
            }

            if (tmp > result)
                result = tmp;
        }
    }
    std::cout << result << std::endl;
    return 0;
}