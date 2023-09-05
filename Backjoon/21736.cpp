#include <iostream>
#include <string>
#include <queue>

#define DEFAULT 0
#define WALL 1
#define PERSON 2

int N, M;
int map[602][602];
bool visit[602][602];

std::pair<int, int> start;

int result = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void solve() {
    std::queue<std::pair<int, int> > q;

    q.push(start);
    while (!q.empty()) {
        std::pair<int, int> elem = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = elem.first + dx[i];
            int newY = elem.second + dy[i];

            if (newX < 0 || newX >= N || newY < 0 || newY >= M)
                continue;
            if (visit[newX][newY] || map[newX][newY] == WALL)
                continue;
            
            visit[newX][newY] = true;
            if (map[newX][newY] == PERSON)
                result++;
            q.push({newX, newY});
        }
    }

}
int main() {
    std::string info;

    std::cin >> N >> M;
    for (int i = 0;i < N; i++) {
        std::cin >> info;
        for (int j = 0; j < M; j++) {
            map[i][j] = DEFAULT;
            if (info[j] == 'X')
                map[i][j] = WALL;
            else if (info[j] == 'I') 
                start = {i, j};
            else if (info[j] == 'P')
                map[i][j] = PERSON;
        }
    }

    solve();

    if (result > 0)
        std::cout << result << std::endl;
    else
        std::cout << "TT\n";
    
    return 0;
}