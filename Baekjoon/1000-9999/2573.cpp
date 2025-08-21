#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int arr[301][301];
int save[301][301];
bool visited[301][301];

int check() {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && arr[i][j]) {
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    
                    for (int k = 0; k < 4; k++) {
                        int newX = cur.first + "2011"[k] - '1';
                        int newY = cur.second + "1120"[k] - '1';

                        if (newX < 0 || newX >= N || newY < 0 || newY >= M) continue;
                        if (visited[newX][newY] || arr[newX][newY] == 0) continue;

                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

void solve() {
    memset(save, 0, sizeof(save));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int newX = i + "2011"[k] - '1';
                    int newY = j + "1120"[k] - '1';

                    if (newX < 0 || newX >= N || newY < 0 || newY >= M) continue;
                    if (arr[newX][newY] == 0) cnt++;
                }
                save[i][j] = (arr[i][j] - cnt > 0) ? arr[i][j] - cnt : 0;
            } 
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = save[i][j];
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) flag = true;
        }
    }

    if (!flag) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    while (true) {
        int ret = check();
        if (ret == 0) {
            cout << 0 << endl;
            return 0;
        }
        else if (ret >= 2) {
            cout << cnt << endl;
            break;
        }
        solve();
        cnt++;
    }
    return 0;
}