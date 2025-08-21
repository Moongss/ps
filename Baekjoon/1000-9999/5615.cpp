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

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ull MulMod(ull a, ull b, ull mod) {
    return (__uint128_t)a * b % mod;
}
  
ull PowMod(ull a, ull b, ull mod) {
    ull ret = 1; a = a % mod;
    while (b) {
        if (b & 1) ret = MulMod(ret, a, mod);
        a = MulMod(a, a, mod);
        b >>= 1;
    }
    return ret;
}

bool MillerRabin(ull x, ull a) {
    if (x == a) return true;
    if (x % a == 0) return false;
    ull k = x - 1; // x = 2^r * d + 1, k = d * 2^r

    while (1) {
        ull tmp = PowMod(a, k, x);
        if (k & 1) return (tmp == 1 || tmp == x - 1);
        else if (tmp == x - 1) return true;
        k >>= 1;
    }
}

bool IsPrime(ull n) {
    if (n == 1) return false; // wa: not check
    // for (auto a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}) {
    for (auto a : {2, 7, 61}) {
        if (n == a) return true;
        if (n > 61 && !MillerRabin(n, a)) return false; // wa: not check
    }
    if (n <= 61) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
    }
    return true;
}

  
int main() {
    fastio;
    ll t; cin >> t;
    int cnt = 0;
    while (t--) {
        ll x; cin >> x; x *= 2; x += 1;
        if (IsPrime(x)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}