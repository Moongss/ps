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
    ll result = 0;
    for (int i = 0; i < N; i++) {
        ll p; cin >> p;
        if (p % 4 == 3) result ^= (p + 1);
        else if (p % 4 == 0) result ^= (p - 1);
        else result ^= p;
    }
    cout << (result ? "koosaga" : "cubelover") << endl;
    return 0;
}