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

int N, M, R;
vector<int> adj[101010];
ll depth[101010];
ll ans;
ll cnt;

void dfs(int cur) {
    ans += depth[cur] * (++cnt);
    for (int nxt : adj[cur]) {
        if (depth[nxt] != -1) continue;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}

int main() {
    fastio;
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) sort(all(adj[i]));
    for (int i = 1; i <= N; i++) depth[i] = -1;
    
    depth[R] = 0;
    dfs(R);
    
    cout << ans << endl;
    return 0;
}