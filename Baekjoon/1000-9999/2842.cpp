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

int N;
char arr[50][50];
bool visited[50][50];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int w[50][50];
int main() {
    fastio;
    
    cin >> N;

    pii s; int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'P') s = {i, j};
            if (arr[i][j] == 'K') cnt++;
        }
    }

    vector<int> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> w[i][j];
            v.push_back(w[i][j]);
        }
    }

    compress(v);
    int l = 0, r = 0;
    int ret = 42424242;
    while (l <= r && r < v.size()) {
        // bfs
        int tmp = 0;

        queue<pii> q; q.push(s);    
        memset(visited, 0, sizeof(visited)); visited[s.x][s.y] = true;

        if (!(v[l] <= w[s.x][s.y] && w[s.x][s.y] <= v[r])) {
            r++; continue;
        }
        while (!q.empty()) {
            pii cur = q.front(); q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[nx][ny]) continue;
                if (!(v[l] <= w[nx][ny] && w[nx][ny] <= v[r])) continue;

                if (arr[nx][ny] == 'K') tmp++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }   

        if (tmp == cnt) ret = min(ret, abs(v[l]-v[r])), l++;
        else r++;
    }
    cout << ret << endl;
    return 0;

}