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

// struct Edge {
//     int nxt;
//     ll t;

//     Edge(int nxt, ll t) : nxt(nxt), t(t) {}
//     bool operator<(const Edge& e) const {
//         return t < e.t;
//     }
// };

bool sieve[10000011];
void getSieve() {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) continue;
        for (int j = i + i; j <= 10000000; j += i) sieve[j] = true;
    }
}

int N, M;
int d[400001];
vector<pll> adj[400001];
ll dist[400001];

void solve(int s) {
    dist[s] = 0;
    priority_queue<pll> pq;

    pq.push({0, s});
    while (!pq.empty()) {
        auto [t, cur] = pq.top(); pq.pop();
        t = -t;

        if (dist[cur] < t) continue;

        for (auto [nt, nxt] : adj[cur]) {
            if (dist[nxt] > (t + nt)) {
                dist[nxt] = t + nt;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
}

int main() {
    fastio;
    
    getSieve();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> d[i];
    for (int i = 1; i <= M; i++) {
        int u, v, t; cin >> u >> v >> t;
        if (!sieve[d[u] + d[v]]) { // not is true
            adj[u].push_back({t, v});
            adj[v].push_back({t, u});
        }
    }

    for (int i = 1; i <= N; i++) dist[i] = LLONG_MAX;
    solve(1);

    if (dist[N] == LLONG_MAX) cout << "Now where are you?" << endl;
    else cout << dist[N] << endl;
    return 0;
}