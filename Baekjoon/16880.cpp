#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int getGrundy(ll x, ll y, char flag) {
    if (flag == 'R') return x ^ y;
    if (flag == 'B') return min(x, y);
    if (flag == 'K') return ((x ^ y) & 1) + (min(x, y) & 1) * 2;
    if (flag == 'N') {
        int mod = min(x, y) % 3;
        if (mod == 0) return 0;
        if (mod == 1) return (x == y ? 0 : 1);
        if (abs(x - y) <= 1) return 1;
        return 2;
    }
    if (flag == 'P') return ((x / 3) ^ (y / 3)) * 3 + (x + y) % 3;
}

int main() {
    fastio;
    
    int N; cin >> N;
    ll result = 0;
    while (N--) {
        ll x, y; char flag; cin >> x >> y >> flag;
        result ^= getGrundy(x, y, flag);
    }
    cout << (result ? "koosaga" : "cubelover") << endl;
    return 0;
}