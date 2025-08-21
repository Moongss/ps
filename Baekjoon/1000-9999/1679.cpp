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

int N, K;
int dp[50001];

int main() {
    fastio;
    
    cin >> N; vector<int> v(N); for (auto &i : v) cin >> i;
    cin >> K;

    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    for (auto &e : v) {
        for (int i = e; i <= 50000; i++) {
            dp[i] = min(dp[i], dp[i - e] + 1);
        }
    }

    for (int i = 1;;i++) {
        if (dp[i] > K) {
            cout << (i % 2 ? "jjaksoon" : "holsoon") << " win at " << i << endl;
            break;
        }
    }
    return 0;
}