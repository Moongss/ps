#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> adj[1000001];
bool visited[1000001];
int dp[2][1000001];

void solve(int cur, int level) {
    visited[cur] = true;
    dp[0][cur] = 1;
    for (auto nxt : adj[cur]) {
        if (visited[nxt]) continue;
        solve(nxt, level + 1);
        dp[0][cur] += min(dp[1][nxt], dp[0][nxt]);
        dp[1][cur] += dp[0][nxt];
    }
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1, 1);
    cout << min(dp[1][1], dp[0][1]) << endl;
    return 0;
}