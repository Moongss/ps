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

int arr[301][301];
int main() {
    fastio;
    
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    }

    int K; cin >> K;
    while (K--) {
        int i, j, x, y; cin >> i >> j >> x >> y;
        int ans = 0;
        for (int k = i; k <= x; k++) {
            ans += arr[k][y] - arr[k][j - 1];
        }
        cout << ans << endl;
    }
    return 0;
}