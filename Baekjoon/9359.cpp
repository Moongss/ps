#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll A, B, N; cin >> A >> B >> N;

        vector<ll> v;
        for (ll i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                v.push_back(i);
                while (N % i == 0) N /= i;
            }
        }
        if (N > 1) v.push_back(N);
        sort(v.begin(), v.end());

        // for (auto &i : v) cout << i << " ";

        ll ans = 0;
        for (int i = 1; i < (1 << v.size()); i++) {
            ll mod = 1;
            int cnt = 0;
            for (int j = 0; j < v.size(); j++) {
                if (i & (1 << j)) {mod = lcm(mod, v[j]); cnt++;}
            }

            ll mod2 = B / mod - (A - 1) / mod;
            if (cnt % 2 == 0) ans -= mod2;
            else ans += mod2;
        }
        cout << "Case #" << t << ": " << (B - A + 1) - ans << endl;
    }
    return 0;
}