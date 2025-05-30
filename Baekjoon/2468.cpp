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

int n; 
int arr[101][101];
bool visited[101][101];
bool valid[101][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    // fastio;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int ret = -1;
    memset(valid, 1, sizeof(valid));
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] <= i) {
                    valid[j][k] = false;
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (valid[j][k] && !visited[j][k]) {
                    queue<pii> q; q.push({j, k});
                    visited[j][k] = true;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int l = 0; l < 4; l++) {
                            int nx = x + dx[l]; 
                            int ny = y + dy[l];
                            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                            if (valid[nx][ny] && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                    cnt++;
                }
            }
        }

        ret = max(ret, cnt);
    }
    cout << ret << endl;

    return 0;
}