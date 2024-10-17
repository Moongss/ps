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

// 10^17
set<ll> s;
int main() {
    fastio;
    
    ll a = 1;
    while (a < 1e+17) {
        for (ll i = 1; i < 10; i++) {
            s.insert(a * i);
        }
        a = a * 10 + 1;
    }


    int T; cin >> T;
    while (T--) {
        ll N, K; cin >> N >> K;

        vector<ll> v; v.clear();
        while (K > 0) {
            auto e = s.lower_bound(K);
            if (*e != K) e--;
            K -= *e;
            v.push_back(*e);
        }

        cout << v.size() << endl;
        for (auto &e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}