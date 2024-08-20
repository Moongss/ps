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

int main() {
    fastio;
    
    int N; cin >> N;
    vector<int> v(N + 3); for (int i = 0; i < N; i++) cin >> v[i];
    sort(all(v), greater<int>());

    int ans = 0;
    if (N % 3 == 0) ans = v[0] + v[N / 3] + v[(N / 3) * 2];
    if (N % 3 == 1) ans = v[0] + v[(N / 3) + 1] + v[(N / 3) * 2 + 1];
    if (N % 3 == 2) ans = v[0] + v[(N / 3) + 1] + v[(N / 3) * 2 + 2];

    for (int i = 0; i < N; i++) {
        if (i == 3) break;
        ans -= i;
    }
    cout << ans << endl;
    return 0;
}