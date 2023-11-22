#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define WALL '*'
#define DOCS '$'
#define SPACE '.'

using namespace std;
using ll = long long;
using ld = long double;

int T, H, W;
char plan[101][101];
bool visited[101][101];
bool key[26];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };
int ans;

void init() {
    memset(plan, 0, sizeof(plan));
    memset(key, 0, sizeof(key));
    ans = 0;
}

int solve() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if ((i == 1 || i == H || j == 1 || j == W) && plan[i][j] != WALL) {
                q.push({ i, j });
                visited[i][j] = true;
            }
        }
    }

    ans = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (plan[x][y] == '$') ans++;
        if ('a' <= plan[x][y] && plan[x][y] <= 'z') key[plan[x][y] - 'a'] = true;
        if (('A' <= plan[x][y] && plan[x][y] <= 'Z') && !key[plan[x][y] - 'A']) continue;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 1 || newX > H || newY < 1 || newY > W) continue;
            if (visited[newX][newY] || plan[newX][newY] == WALL) continue;

            visited[newX][newY] = true;
            q.push({newX, newY});
        }
    }

    int moveCnt = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (visited[i][j]) moveCnt++;
        }
    }
    return moveCnt;
}

int main() {
    fastio;
    cin >> T;
    while (T--) {
        init();
        cin >> H >> W;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++){
                cin >> plan[i][j];
            }   
        }

        string keys; cin >> keys;
        for (int i = 0; i < keys.size(); i++) {
            if (keys[i] == '0') break;
            key[keys[i] - 'a'] = true;
        }

        int prevCnt = -1;
        while (true) {
            int moveCnt = solve();
            if (prevCnt == moveCnt) break;
            prevCnt = moveCnt;
        }
        cout << ans << endl;
    }
    return 0;
}