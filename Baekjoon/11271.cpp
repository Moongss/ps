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

int N, K;
vector<pll> v;

int main() {
    fastio;
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(all(v), [&](pll a, pll b) {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    ll ret = 0;
    stack<ll> tmp;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < N; i++) {
        while (!pq.empty() && pq.top() <= v[i].x) {
            tmp.push(pq.top()), pq.pop();
        }
        if (!tmp.empty()) tmp.pop();
        while (!tmp.empty()) pq.push(tmp.top()), tmp.pop();

        if (pq.size() < K) {
            pq.push(v[i].y);
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}
