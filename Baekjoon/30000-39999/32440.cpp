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
#define sz(v) (int)v.size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll mod = 1e9 + 7;
const ll inf = (1LL << 63) - 1;
int N, Q;
int mu[1200000] = {0, };
int allcnt[1010101];
vector<int> v;

vector<int> getelem(ll n) {
    // set 넣기.
    vector<int> s; 
    ll tmp = n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            s.push_back(i);
        }
    }
    s.push_back(n);
    return s;
}

//use mobius function
void init() {
    mu[1] = 1;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 2 * i; j <= 1000000; j += i) {
            mu[j] -= mu[i];
        }
    }

    for (auto &x : v) {
        unordered_set<int> s = getelem(x);
        for (auto &i : s) {
            allcnt[i]++;
        }
    }
}

ll solve(ll n) {
    ll cnt = 0;
    unordered_set<int> prime = getelem(n);
    for (auto &i : prime) {
        cnt += ((mu[i] % mod) * (allcnt[i] % mod)) % mod;
        // cout << "mu * allcnt : " << mu[i] << " * " << allcnt[i] << endl;
    }
    return cnt;
}

ll powmod(ll a, ll b, ll c) {
    if (c == 1) return 0;
    ll res = 1;
    for (a%=c; b; b>>=1, a = a * a % c) if (b&1) res = res * a % c;
    return res%c;
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    init();
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        // cout << "solve(q) : " << solve(q) << endl;
        // if (q == 1 || q > Max) cout << powmod(2, N, mod) << endl;
        cout << powmod(2, solve(q), mod) << endl;
    }
    return 0;
}