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

ll arr[303][303];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(arr, 0, sizeof(arr));
        int R, C; cin >> R >> C;
        priority_queue<pair<int, pii>> pq;

        ll mmax = -1;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> arr[i][j];
                pq.push({arr[i][j], {i, j}});
            }
        }

        ll sum = 0;
        while (!pq.empty()) {
            auto [n, e] = pq.top(); pq.pop();
            if (n != arr[e.x][e.y]) continue;

            bool f = false;
            for (int i = 0; i < 4; i++) {
                int nx = e.x + dx[i];
                int ny = e.y + dy[i];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (abs(arr[nx][ny] - arr[e.x][e.y]) <= 1) continue;

                sum += abs(arr[nx][ny] - arr[e.x][e.y]) - 1;
                arr[nx][ny] += abs(arr[nx][ny] - arr[e.x][e.y]) - 1;
                pq.push({arr[nx][ny], {nx, ny}});
            }
        }
        cout << "Case #" << t << ": " << sum << endl;
    }
    return 0;
}