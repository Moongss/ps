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
    
    int N, M; cin >> N >> M;
    vector<pii> v; v.resize(M);
    for (auto &e : v) cin >> e.x >> e.y;

    int cur = 0;
    deque<pii> dq;
    for (int i = 1; i < 1010; i++) {
        if (cur == M) break;
        auto [p, t] = v[cur];
        int time = p + t;

        while (!dq.empty()) {
            if (dq.front().y > i) break;
            dq.pop_front();
        }

        while (dq.size() < N) {
            int nxt = dq.empty() ? 1 : dq.back().x + 1;
            if (nxt > N) break;
            if (cur == M) break;
            if (i < v[cur].x) break;

            dq.push_back({nxt, i + v[cur].y});
            cur++;
        }
    }
    cout << dq.back().x << endl;
    return 0;
}