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

map<int, int> m;
int main() {
    fastio;
    
    int N, M; cin >> N >> M;
    for (int i = 0; i <N; i++) {
        int x; cin >> x; m[x]++;
    }
    
    int ret = 0;
    for (auto &e : m) {
        ret = max(ret, e.y);
    }
    cout << ret << endl;
    return 0;
}