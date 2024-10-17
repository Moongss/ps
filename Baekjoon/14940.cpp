#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
#define x first
#define y second

using namespace std;
using pii = pair<int, int>;

int N, M;
int arr[1010][1010];
int ans[1010][1010];
bool visited[1010][1010];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve(pii s) {
    queue<pii> q; q.push(s);
    visited[s.x][s.y] = true;

    ans[s.x][s.y] = 0;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny] || arr[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            ans[nx][ny] = ans[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    pii start;

    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) ans[i][j] = 0;
            if (arr[i][j] == 2) start = {i, j};
        }
    }
        
    solve(start);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}