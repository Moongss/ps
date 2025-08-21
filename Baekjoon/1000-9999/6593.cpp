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

int L, R, C;
int arr[31][31][31];
int visited[31][31][31];


int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

pair<int, pii> s, e;
int main() {
    fastio;
    
    while (true) {
        cin >> L >> R >> C;
        if (L + R + C == 0) break;

        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string str; cin >> str;
                for (int k = 0; k < C; k++) {
                    if (str[k] == 'S') s = {i, {j, k}};
                    if (str[k] == 'E') e = {i, {j, k}};
                    if (str[k] == '#') arr[i][j][k] = -1;
                }
            }
        }

        queue<pair<int, pii>> q;
        q.push(s);
        visited[s.x][s.y.x][s.y.y] = 1;

        int cnt = 0;
        bool f = false;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur == e) {
                cout << "Escaped in " << visited[cur.x][cur.y.x][cur.y.y] - 1 << " minute(s)." << endl;
                f = true;
                break;
            }

            for (int i = 0; i < 6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y.x + dy[i];
                int nz = cur.y.y + dz[i];
                if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
                if (visited[nx][ny][nz]) continue;
                if (arr[nx][ny][nz] < 0) continue;
                visited[nx][ny][nz] = visited[cur.x][cur.y.x][cur.y.y] + 1;
                q.push({nx, {ny, nz}});
            }
        }
        if (!f) cout << "Trapped!" << endl;
    }
    return 0;
}