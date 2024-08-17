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

ll sum = 0;
int N, L, R;
vector<int> v;

int main() {
    fastio;
    
    cin >> N >> L >> R;
    v.resize(N); for (auto &i : v) cin >> i;

    for (int i = 1; i < (1 << N); i++) {
        ll mod = 1;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {mod = lcm(mod, v[j]); cnt++;}
        }

        ll mod2 = R / mod - (L - 1) / mod;
        if (cnt % 2 == 0) sum -= mod2;
        else sum += mod2;
    }
    cout << sum << endl;
    return 0;
}