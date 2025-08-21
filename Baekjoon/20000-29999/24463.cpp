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

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N,M;
char arr[2020][2020];
bool visited[2020][2020];
pii checked[2020][2020];
vector<pii> ret;


void solve(pii s, pii e) {
    queue<pii> q;
    visited[s.x][s.y] = true;
    q.push(s);

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        
        if (x == e.x && y == e.y) break;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] == '+') continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny});
            checked[nx][ny] = {x, y};
        }
    }

    for (pii p = e; p != s; p = checked[p.x][p.y]) {
        arr[p.x][p.y] = '@';
    }
    arr[s.x][s.y] = '@';

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == '@') cout << '.';
            else if (arr[i][j] == '.') cout << '@';
            else cout << arr[i][j];
        }
        cout << endl;
    }
}
int main() {
    fastio;
    
    cin >> N >> M;
    pii start; pii end;
    start = end = {0, 0};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.' && (i == 1 || j == 1 || i == N || j == M)) {
                if (!start.x) start = {i, j};
                else end = {i, j};
            } 
        }
    }

    solve(start, end);
    return 0;
}