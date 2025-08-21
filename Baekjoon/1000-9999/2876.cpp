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

int N;
int dp[100001][6];
int main() {
    fastio;
    
    cin >> N;
    pii ret = {0, 42};
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        dp[i][x] = max(1, dp[i - 1][x] + 1);
        dp[i][y] = max(1, dp[i - 1][y] + 1);

        for (int j = 1; j <= 5; j++) {
            if (ret.x < dp[i][j] ||
                ret.x == dp[i][j] && ret.y > j) ret = {dp[i][j], j};
        }
    }
    cout << ret.x << " " << ret.y << endl;
    return 0;
}