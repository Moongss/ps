#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, K;
int arr[52][52];
bool visited[52][52];

// R L D U
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int tile[6][2] = {
    {0, 2},
    {1, 2},
    {0, 3},
    {1, 3},
    {2, 3},
    {0, 1}
};

int solve() {
    memset(visited, 0, sizeof(visited));
    queue<pair<pii, int>> q;

    if (arr[1][1] != 1 && arr[1][1] != 5) return -1;
    q.push({{1, 1}, 1});
    visited[1][1] = 1;

    while (!q.empty()) {
        auto [c, d] = q.front(); q.pop();
        auto [x, y] = c;

        if (x == N && y == N) {
            if (arr[x][y] == 2 || arr[x][y] == 5) return d;
            else return -1;
        }

        for (int i = 0; i < 2; i++) {
            int dir = tile[arr[x][y]][i];
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visited[nx][ny]) continue;

            // R L D U
            if (dir == 0 && (arr[nx][ny] % 2 == 1) || 
                dir == 1 && (arr[nx][ny] == 0 || arr[nx][ny] == 2 || arr[nx][ny] == 5) ||
                dir == 2 && (arr[nx][ny] >= 2 && arr[nx][ny] <= 4) ||
                dir == 3 && (arr[nx][ny] == 0 || arr[nx][ny] == 1 || arr[nx][ny] == 4)) {
                visited[nx][ny] = 1;
                q.push({{nx, ny}, d + 1});
            }
        }
    }
    return -1;
}

int main() {
    fastio;
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    int sum = 0x3f3f3f3f;
    if (K) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int tmp = arr[i][j];
                for (int k = 0; k < 6; k++) {
                    if (k == tmp) continue;
                    else arr[i][j] = k;

                    int ret = solve();
                    if (ret > 0) sum = min(sum, ret);
                }
                arr[i][j] = tmp;
            }
        }
    } else {
        int ret = solve();
        if (ret > 0) sum = min(sum, ret);
    }

    if (sum == 0x3f3f3f3f) cout << -1 << endl;
    else cout << sum << endl;
    return 0;
}