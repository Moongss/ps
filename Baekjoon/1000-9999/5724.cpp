#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    ll N;
    while (cin >> N) {
        if (N == 0) break;
        ll cnt = 0;
        for (ll i = 0; i < N; i++) {
            cnt += (N - i) * (N - i);
        }
        cout << cnt << endl;
    }
    return 0;
}