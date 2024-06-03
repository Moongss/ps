#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    int K, D1, D2;
    cin >> K >> D1 >> D2;

    int res = 4 * K * K - (D1-D2) * (D1-D2);
    cout << res / 4.0 << endl;
    return 0;
}