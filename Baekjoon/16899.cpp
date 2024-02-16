#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll getGrundy(ll n) {
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    if (n % 4 == 3) return 0;
    return n;
}

int main() {
    fastio;
    
    ll N; cin >> N;
    ll result = 0;
    while (N--) {
        ll X, M; cin >> X >> M;
        result ^= getGrundy(X + M - 1);
        result ^= getGrundy(X - 1);
    }

    cout << (result ? "koosaga" : "cubelover") << endl;
    return 0;
}