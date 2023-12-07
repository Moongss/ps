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
    
    int T; cin >> T;
    while (T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) cout << -1 << endl;
            else cout << 0 << endl;
        } 
        else {
            int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            int r = (r1 + r2) * (r1 + r2);
            if (d == r) cout << 1 << endl;
            else if (d > r) cout << 0 << endl;
            else { // 큰원안에 작은원 
                if (d > (r1 - r2) * (r1 - r2)) cout << 2 << endl;
                else if (d == (r1 - r2) * (r1 - r2)) cout << 1 << endl;
                else cout << 0 << endl;
            }
        }
    }
    return 0;
}