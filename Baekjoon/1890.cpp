#include <iostream>
#include <queue>

using ll = long long;
int N;
int map[100][100];
ll save = 0;
std::queue<std::pair<int, int> >q;

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    q.push(std::make_pair(0, 0));
    while (!q.empty()) {
        std::pair<int, int> elem = q.front();
        q.pop();
        int x = elem.first;
        int y = elem.second;
        if (x == N - 1 && y == N - 1) {
            save++;
            continue;
        }

        if (y + map[x][y] < N) {
            q.push(std::make_pair(x, y + map[x][y]));
        }
        if (x + map[x][y] < N) {
            q.push(std::make_pair(x + map[x][y], y));
        }
    }
    std::cout << save << std::endl;
    return 0;
}