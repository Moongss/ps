#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

ll basis[61];
int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        memset(basis, 0, sizeof(basis));

        ll sum = 0;
        while (N--) {
            ll x; cin >> x;
            sum ^= x;
            for (int i = 60; i >= 0; i--) {
                if (x & (1LL << i)) {
                    if (basis[i]) x ^= basis[i];
                    else {
                        basis[i] = x;
                        break;
                    }
                }
            }
        }

        for (int i = 60; i >= 0; i--) {
            if (basis[i]) {
                cout << abs(sum ^ basis[i] - basis[i]) << endl;
                break;
            }
        }
    }
    return 0;
}