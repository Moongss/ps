#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int arr[50][50];
bool visited[50][50];
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
    fastio;
    while (true) {
        int w, h; cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }        

        int cnt = 0;
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (int k = 0; k < 8; k++) {
                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            if (newX < 0 || newX >= h || newY < 0 || newY >= w) continue;
                            if (arr[newX][newY] == 0 || visited[newX][newY]) continue;
                            visited[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}