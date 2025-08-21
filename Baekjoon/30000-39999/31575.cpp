#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
bool visited[301][301];
int arr[301][301];

bool bfs(pii s) {
    queue<pii> q;
    q.push(s);
    visited[s.first][s.second] = true;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
    
        if (cur.first == M - 1 && cur.second == N - 1) return true;
        for (int i = 0; i < 2; i++) {
            int nx = cur.first + "12"[i] - '1';
            int ny = cur.second + "21"[i] - '1';

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (arr[nx][ny] == 0) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return false;
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));
    cout << (bfs({0, 0}) ? "Yes" : "No") << endl;
    return 0;
}