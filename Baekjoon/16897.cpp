#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T;

int main() {
    fastio;

    // int k = 1; k++;
    // for (int i = 1; i <= 20; i++) {
    //     for (int j = 1; j <= 20; j++) {
    //         ll res = (i & 1) ^ (j & 1);
    //         if ((i % k == 0 && j >= i) || (j % k == 0 && i >= j)) res += 2;

    //         if (k > 2) {
    //             if (!((i % k == 0 && j >= i) || (j % k == 0 && i >= j)))
    //                 res ^= (min(i, j) / k) % 2;
    //         }
    //         cout << res << " ";
    //     }
    //     cout << endl;
    // }

    cin >> T;
    while (T--) {
        ll K, N, M; cin >> K >> N >> M; K++;

        ll res = (N & 1) ^ (M & 1);
        if ((N % K == 0 && M >= N) || (M % K == 0 && N >= M)) res += 2;
        if (K >  2 && (!(N % K == 0 && M >= N) || (M % K == 0 && N >= M))) res ^= (min(N, M) / K) % 2;

        cout << (res ? "koosaga" : "cubelover") << endl;
    }

    return 0;
}