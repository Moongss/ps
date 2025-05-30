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

int main() {
    fastio;
    
    vector<ll> v;
    ll i = 11111'11111'11111'111;
    for (int j = 1; j <= 9; j++) {
        ll tmp = i * j;
        for (int l = 1; l <= 18; l++) {
            v.push_back(tmp % (ll)pow(10, l));
        }
    }
    sort(all(v));

    ll l, r; cin >> l >> r;
    cout << upper(v, r) - lower(v, l) << endl;


    return 0;
}