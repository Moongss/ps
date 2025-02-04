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

ll N, K;

ll solve(ll n) {
    if (K == 1) return N-1; // wa: segfault
    if (n == 1) return 0; // 살아나는걸 구했음!
    if (K > n) return (solve(n - 1) + K) % n; // 11025
    else {
        // 보정작업을 해줘야함
        ll tmp = solve(n - n/K) - n%K;
        if (tmp < 0) tmp += n;
        else tmp += tmp / (K - 1); //K == 1이면 여기서 걸림
        return tmp;

    }
}
int main() {
    fastio;
    
    cin >> N >> K;
    cout << solve(N) + 1 << endl;
    return 0;
}