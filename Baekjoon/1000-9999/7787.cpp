#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int getGrundy(ll n) {
    int cnt = 0;
    while (n / 4 && n % 4 == 0) {
        n /= 4;
        cnt++;
    }
    return (cnt * 2 + ((n % 2) ? 1 : 2));
}

int main() {
    ll x, y; cin >> x >> y;
    ll mex = 0;
    mex ^= getGrundy(x);
    mex ^= getGrundy(y);
    cout << (mex ? "A player wins" : "B player wins") << endl;
    return 0;
}
// GRUNDY TEST
// int g[10001];
// int getGrundy(int x) {
//     set<int> s;
//     for (int i = 1; i <= x / 2; i++) {
//         if (x % i == 0) {
//             s.insert(g[x - i]);
//         }
//     }
//     s.insert(0);

//     int mex = 0;
//     for (auto &x : s) {
//         if (mex == x) mex++;
//         else break;
//     }
//     return mex;
// }

// int main() {
//     fastio;
    
//     g[0] = 0;
//     g[1] = 1;
//     for (int i = 1; i <= 10000; i++) {
//         int ret = getGrundy(i);
//         g[i] = ret;
//         // cout << ret << " ";
//         // if (i % 4 == 0) cout << endl;
//         if (i % 4 == 0) cout << ret;
//         if (i % 16 == 0) cout << endl;
//     }
//     return 0;
// }