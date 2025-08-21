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

ll m;
ll pow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b % 2) ret = ((ret % m) * (a % m)) % m;
        a = ((a % m) * (a % m)) % m;
        b /= 2;
    }
    return ret;
}

int main() {
    fastio;
    
    int N;
    cin >> N;
    ll a, b, c;

    if (N == 0) {cin >> a >> m; cout << a % m << endl;}
    if (N == 1) {cin >> a >> b >> m; cout << pow(b, a) % m << endl;}
    if (N == 2) {cin >> a >> b >> c >> m; cout << pow(c, pow(b, a)) % m << endl;}
    return 0;
}