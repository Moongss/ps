#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
vector<ll> v;

ll sum = 1;

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    int cnt = 0;
    for (int i = 0; i < (1 << N); i++) {
        ll under = 1;
        ll upper = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                under *= v[j];
            }
        }

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                upper += under / v[j];
            }
        }

        if (under * 99 <= 100 * upper && upper * 100 <= under * 101) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}