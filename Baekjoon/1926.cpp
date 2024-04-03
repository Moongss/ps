#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int arr[501][501];
bool visited[501][501];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int bfs(int i, int j) {
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;

    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newX >= N || newY < 0 || newY >= M) continue;
            if (arr[newX][newY] == 0) continue;
            if (visited[newX][newY]) continue;

            visited[newX][newY] = true;
            q.push({newX, newY});
        }
    }
    return cnt;
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int maxSize = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] && !visited[i][j]) {
                maxSize = max(maxSize, bfs(i, j));
                cnt++;
            }
        }
    }

    cout << cnt << endl << maxSize << endl;
    return 0;
}