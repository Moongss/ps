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