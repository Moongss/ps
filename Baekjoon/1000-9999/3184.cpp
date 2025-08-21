#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int R, C; 
char arr[250][250];
bool visited[250][250];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int rs, rw;

void bfs(int i, int j) {
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;

    int s, w; s = w = 0;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        if (arr[cx][cy] == 'o') s++;
        if (arr[cx][cy] == 'v') w++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (arr[nx][ny] == '#' || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if (s > w) rs += s;
    else rw += w;
}

int main() {
    fastio;
    
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    rs = rw = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == '#' || visited[i][j]) continue;
            bfs(i, j);
        }
    }

    cout << rs << " " << rw << endl;
    return 0;
}