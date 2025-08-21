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

ll dp[5050505];

int main() {
    fastio;

    int N, K; cin >> N >> K;
    // f(n, k) = (f(n-1, k) + k) % n
    // f(1, k) = 0

    int ans = 0; // n = 0
    for (int i = 1; i <= N; i++) {
        ans = (ans + K) % i;
    }
    cout << ans + 1 << endl;
    return 0;
}