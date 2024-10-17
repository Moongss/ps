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

set<ll> s;
int main() {
    fastio;
    
    ll N; cin >> N; if (!N) {cout << "NO" << endl; return 0;}
    ll t = 1; vector<ll> v;
    for (ll i = 1; t <= 1e18; i++) {
        v.push_back(t); t *= i;
    }

    for (int i = v.size() - 1; i >= 0 && N; i--) {
        if (N - v[i] >= 0) N -= v[i];
    }
    cout << (N ? "NO" : "YES") << endl;
    return 0;
}