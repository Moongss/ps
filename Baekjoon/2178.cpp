#include <iostream>
#include <queue>

int maze[102][102] = {0, };
int minimumPath[102][102] = {0, };
// bool isVisited[102][102] = {0, };

int N, M;
std::queue<std::pair<int, int> > tmp;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    maze[0][0] = 0;
    minimumPath[1][1] = 1;
    tmp.push(std::make_pair(1, 1));

    while (!tmp.empty()) {
        std::pair<int, int> coordinate = tmp.front();

        int y = coordinate.first;
        int x = coordinate.second;
        tmp.pop();

        for (int i = 0; i < 4; i++) {
            if (maze[y + dy[i]][x + dx[i]] > 0) {
                minimumPath[y + dy[i]][x + dx[i]] = minimumPath[y][x] + 1;
                maze[y + dy[i]][x + dx[i]] = 0;
                tmp.push(std::make_pair(y + dy[i], x + dx[i]));
            }
        }
    }
}

int main() {
    std::string mazeLine;
    
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        std::cin >> mazeLine;
        for (int j = 1; j <= M; j++) {
            maze[i][j] = mazeLine[j - 1] - '0';
        }
    }


    solve();

    std::cout << minimumPath[N][M] << std::endl;
    return 0;
}