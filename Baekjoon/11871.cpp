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
    ll N; cin >> N;

    ll result = 0;

    //0, 2, 4, 6, 8 -> 0, 0, 1, 2, 3
    //1, 3, 5, 7, 9 -> 1, 2, 3, 4, 5
    for (int i = 0; i < N; i++) {
        ll p; cin >> p;
        if (p % 2 == 0) result ^= (p - 1) / 2;
        if (p % 2 != 0) result ^= (p + 1) / 2;
    }

    cout << (result ? "koosaga" : "cubelover") << endl;
    return 0;
}