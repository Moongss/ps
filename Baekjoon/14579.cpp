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
    
    int a, b; cin >>a >> b;

    ll pre = 0;
    for (int i = 1; i < a; i++) {
        pre += i;
    }

    ll ans = 1;
    for (int i = a; i <= b; i++) {
        ans = ans * (pre + i) % 14579;
        pre += i;
    }
    cout << ans << endl;
    return 0;
}