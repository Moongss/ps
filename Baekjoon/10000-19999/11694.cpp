#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N; cin >> N;

    ll grundy = 0;
    int oneCount = 0;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        grundy ^= x;
        if (x == 1) oneCount++;
    }

    if (oneCount == N) {
        cout << (N % 2 == 0 ? "koosaga" : "cubelover") << endl;
    }
    else {
        cout << (grundy == 0 ? "cubelover" : "koosaga") << endl;
    }

    return 0;
}