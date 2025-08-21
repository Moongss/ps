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
    
    int M, N; cin >> N >> M;
    bool f = true;
    while (M--) {
        int m; cin >> m;
        int prev; cin >> prev;
        for (int i = 0; i < m - 1; i++) {
            int x; cin >> x;
            if (x > prev) {
                f = false;
            }
            prev = x;
        }
    }
    if (!f) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}