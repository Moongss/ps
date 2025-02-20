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

ll N, t;
vector<pll> v;
vector<ll> v2;
int main() {
    fastio;
    
    cin >> N >> t;
    int k = 0;
    for (int i=0; i < N; i++) {
        ll x, vv; cin >> x >> vv;
        if (i == 0) k = x;
        v.push_back({x, vv});
        v2.push_back(x + vv * t);
    }
    sort(all(v)); 
    for (int i=0; i < N; i++) {
        if (v[i].x == k) {
            k = i;
            break;
        }
    }
    sort(all(v2));
    cout << v2[k] << endl;
    
    return 0;
}