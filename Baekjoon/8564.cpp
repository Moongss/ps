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

int N;
int cnt[1010];
vector<int> adj[1010];

void dfs(int cur) {
    cnt[cur] = 1;
    for (int nxt : adj[cur]) {
        if (cnt[nxt]) continue;
        dfs(nxt);
        cnt[cur] += cnt[nxt];
    }
}

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int root = 0;
    for (int i = 1; i <= N; i++) {
        if (adj[i].size() == 1) root = i;
    }
    
    dfs(root);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, cnt[i] * (N - cnt[i]));
    }
    cout << ans << endl;
    return 0;
}