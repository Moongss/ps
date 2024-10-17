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
ll dp[10000001];
int main() {
    fastio;
    
    cin >> N;
    ll ret = 0;
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] += (dp[i - 1] % 10 + dp[i - 2] % 10) % 10;
    }

    cout << dp[N] << endl;
    return 0;
}