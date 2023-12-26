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
    int N, M;
    cin >> N >> M;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            string str; cin >> str;
            int cnt = 0;
            for (int k = 0; k < str.size(); k++) {
                if (str[k] == 'O') cnt++;
            }

            if (cnt > M/2) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}