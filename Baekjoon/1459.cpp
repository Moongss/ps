#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

ll X, Y, W, S;

int main() {
    fastio;
    cin >> X >> Y >> W >> S;
    
    ll ans = 0;
    if (W * 2 <= S) ans = (X + Y) * W;
    else {
        ans = min(X, Y) * S;

        int t = min(X, Y);
        X -= t;
        Y -= t;

        if (max(X, Y) % 2 == 0) {
            ans += max(X, Y) * min(W, S);
        } else {
            if (max(X, Y) > 1)
                ans += (max(X, Y) - 1) * min(W, S);
            ans += W;
        }
    }
    cout << ans << endl;
    return 0;
}