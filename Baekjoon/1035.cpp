#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

char tmp[5][5];
char board[5][5];
int visited[5][5];
bool visited2[5][5];

int ans = 42424242;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0, 0};

void init() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j ++) {
            board[i][j] = tmp[i][j];
        }
    }
}

bool isOne(int cnt) {
    queue<pair<int, int>> q;
    memset(visited2, false, sizeof(visited2));
    bool flag = true;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 ; j++) {
            if (board[i][j] == '*' && flag) {
                q.push({i, j});
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    int tmp = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i];

            if ((nx < 0 || nx >= 5 || ny < 0 || ny >= 5) || visited2[nx][ny]) continue;
            if (board[nx][ny] == '.') continue;

            visited2[nx][ny] = true;
            tmp++;
            q.push({nx, ny});
        }
    }
    return (cnt == tmp);
}

bool check(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    memset(visited2, false, sizeof(visited2));
    visited2[start.first][start.second] = true;

    if (end.first == start.first && end.second == start.second) return true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited2[nx][ny]) continue;
            if (board[nx][ny] == '.') continue;
            if (board[nx][ny] == '*' && end.first == nx && end.second == ny) {
                return true;
            }

            visited2[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return false;
}

int solve(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    memset(visited, false, sizeof(visited));
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == '*') {
                if (!check({nx, ny}, end)) continue;
                board[start.first][start.second] = '.';
                board[x][y] = '*';
                return visited[x][y] - 1;
            }
            if (board[nx][ny] == '.' && (nx == end.first && ny == end.second)) {
                board[start.first][start.second] = '.';
                board[nx][ny] = '*';
                return visited[x][y];
            }
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}

int main() {
    fastio;

    vector<pair<int, int>> v;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char ch; cin >> ch;
            if (ch == '*')
                v.push_back({i, j});
            tmp[i][j] = board[i][j] = ch;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            sort(v.begin(), v.end());
            do {
                init();
                int cnt = 0;
                for (int k = 0; k < v.size(); k++) {
                    if (i == v[k].first && j == v[k].second) continue;
                    cnt += solve(v[k], {i, j}); // s, e
                }
                if(isOne(v.size()))
                    ans = min(ans, cnt);
            } while (next_permutation(v.begin(), v.end()));
        }
    }
    cout << (v.size() == 1 ? 0 : ans) << endl;
    return 0;
}