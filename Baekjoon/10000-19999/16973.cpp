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

int N, M;
int H, W;
pii S, F;

int arr[1001][1001];
int visited[1001][1001];
int pre[1001][1001];
queue<pii> q; 

bool check1(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

bool check2(int x, int y) {
    return ((pre[x + H - 1][y + W - 1] - pre[x - 1][y + W - 1] - pre[x + H - 1][y - 1] + pre[x - 1][y - 1]) == 0);
}

void solve() {
    memset(visited, -1, sizeof(visited));
    q.push(S);
    visited[S.x][S.y] = 0;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto &[x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!check1(nx, ny) || !check1(nx + H - 1, ny + W - 1)) continue;
            if (!check2(nx, ny)) continue;
            if (visited[nx][ny] != -1 && visited[x][y] + 1 >= visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++ ){
            cin >> arr[i][j];
            pre[i][j] = arr[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        }
    }

    cin >> H >> W >> S.x >> S.y >> F.x >> F.y;
    solve();

    cout << visited[F.x][F.y] << endl;
    return 0;
}