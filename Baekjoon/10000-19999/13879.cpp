#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

ll dp[10001];

int main() {
    fastio;
    
    int P; cin >> P;
    while (P--) {
        int K, M, N; cin >> K >> M >> N;
        for (int i = 0; i <= N; i++) dp[i] = 1;

        for (int i = M; i <= N; i *= M) {
            ll pow = i;
            for (int j = pow; j <= N; j++) {
                dp[j] += dp[j - pow];
            }   
        }
        cout << K << " " << dp[N] << endl;
    }
    return 0;
}