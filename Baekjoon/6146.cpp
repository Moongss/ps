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

int X, Y, N;
bool visited[1001][1001];
char arr[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    fastio;
    
    cin >> X >> Y >> N; X += 500; Y += 500;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y; x += 500; y += 500;
        arr[x][y] = 'X';
    }

    queue<pair<int, pii>> q;
    q.push({0, {500, 500}});
    visited[500][500] = true;

    int ret = 0;
    while (!q.empty()) {
        auto [d, e] = q.front(); q.pop();
        auto [x, y] = e;
        if (x == X && y == Y) {
            cout << d << endl;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > 1000 || ny < 0 || ny > 1000) continue;
            if (visited[nx][ny] || arr[nx][ny] == 'X') continue;
            visited[nx][ny] = true;
            q.push({d + 1, {nx, ny}});
        }
    }

    return 0;
}