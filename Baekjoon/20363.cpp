#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll X, Y;
ll ans = 0;

int main() {
    fastio;
    
    cin >> X >> Y;
    cout << X + Y + min(X, Y) / 10 << endl;
    return 0;
}