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
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<pii> v(N); for (auto &i : v) cin >> i.x >> i.y;
        vector<bool> vv(N); for (int i = 0; i < N; i++) vv[i] = false;

        int M; cin >> M;
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int cx, cy; cin >> cx >> cy;
            for (int j = 0; j < v.size(); j++) {
                auto e = v[j];
                if (e.x >= cx - 50 && e.x <= cx + 50 && e.y >= cy - 50 && e.y <= cy + 50 && !vv[j]) cnt++, vv[j] = true;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}