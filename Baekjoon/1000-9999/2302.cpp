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

ll sum = 1;
bool arr[41];
int dp[41];
int main() {
    fastio;
    
    int N, M; cin >> N >> M;
    dp[0] = dp[1] = 1;
    for (int i = 0; i < M; i++) {
        int x; cin >> x; arr[x] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i > 1) dp[i] = dp[i - 1] + dp[i - 2];
        if (arr[i]) {if (cnt) sum *= dp[cnt]; cnt = 0;}
        else cnt++;
    }
    if (cnt) sum *= dp[cnt];
    cout << sum << endl;
    return 0;
}