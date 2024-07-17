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
    
    int a, b, n, w; cin >> a >> b >> n >> w;

    bool flag = false;
    int c, d;
    for (int i = 1; i < n; i++) {
        if (a * i + b * (n - i) == w) {
            if (flag) {
                cout << -1 << endl;
                return 0;
            }
            c = i; d = n - i;
            flag = true;
        }
    }

    if (flag) {
        cout << c << " " << d << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}