#include <bits/stdc++.h>
#include <ext/rope>

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
using namespace __gnu_cxx;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, M;
rope<int> r;
set<int> s;

int main() {
    fastio;

    int N, M; cin >> N >> M;
    for (int i = 1; i <= 2 * M; i++) s.insert(i);
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        
        while (r.size() <= x) r.push_back(0);
        r.insert(x, i);

        auto it = s.lower_bound(x + 1);
        if (it != s.end()) {r.erase(*it, 1); s.erase(it);}
    }
    cout << r.size() - 1 << endl;
    for (int i = 1; i < r.size(); i++) cout << r[i] << " "; cout << endl;
    return 0;
}