#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N, M;
int h, w;
bool visited[1001][1001];
int arr[1001][1001];
int pre[1001][1001];
int K;
int r, c;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void bfs() {
    queue<pair<int, int> >q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        pair<int, int> elem = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = elem.first + dx[i];
            int newY = elem.second + dy[i];
            if (newX < 1 || newX > N || newY < 1 || newY > M)
                continue;
            if (visited[newX][newY])
                continue;
            
            if (arr[newX][newY] >= arr[elem.first][elem.second]) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}
int main() {
    fastio;
    cin >> N >> M;
    cin >> h >> w;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> K;
    while (K--) {
        cin >> r >> c;
        bfs();
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + visited[i][j];
        }
    }

    for (int i = h; i <= N; i++) {
        for (int j = w; j <= M; j++) {
            if (pre[i][j] - pre[i - h][j] - pre[i][j - w] + pre[i - h][j - w] == w * h)
                result++;
        }
    }
    cout << result << endl;
    return 0;
}