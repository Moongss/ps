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

vector<int> v;
int main() {
    fastio;
    
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, M; cin >> N >> M;
        int sum = 0;
        v.clear(); v.resize(N); for (auto &e : v) cin >> e;
        
        for (auto &e : v) {
            auto elem = *lower_bound(all(v), M - e);
            if (e + elem == M) sum++;
            if (e == M / 2 && elem == M / 2) sum++;
        }
        cout << "Case #" << i << ": " << sum / 2 << endl;
    }
    return 0;
}