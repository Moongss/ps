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
    
    int W, N; cin >> W >> N;
    vector<int> v(N); for (auto &i : v) cin >> i;
    sort(all(v));

    int ret = 0;
    int cnt = 0;
    int s = 0, e = N - 1;
    while (s < e) {
        if (v[s] + v[e] <= W) {s++; e--; cnt+=2;}
        else {e--; cnt++;}
        ret++;
    }
    if (cnt < N) ret++;
    cout << ret << endl;
    return 0;
}