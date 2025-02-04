#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int r, c; 
int arr[5][5];
bool visited[5][5];

int ret = 42424242;

void sss(pii cur, int cnt, int sum) {
    if (sum == 3) {
        ret = min(ret, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (visited[nx][ny]) continue;
        if (arr[nx][ny] == -1) continue;

        visited[nx][ny] = true;
        if (arr[nx][ny] == 0) sss({nx, ny}, cnt+1, sum);
        else sss({nx, ny}, cnt+1, sum+1);
        visited[nx][ny] = false;
    }
}
int main() {
    fastio;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    
    cin >> r >> c;
    visited[r][c] = true;
    sss({r, c}, 0, 0);
    
    cout << (ret == 42424242 ? -1 : ret) << endl;
    return 0;
}