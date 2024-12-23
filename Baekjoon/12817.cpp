#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using namespace std;

int N;
int x, y;
vector<int> adj[1010101];
ll dp[1010101];

int dfs(int cur, int prev) {
    dp[cur] = 1;
    for (auto x : adj[cur]) {
        if (x == prev) continue;
        dp[cur] += dfs(x, cur);
    }
    return dp[cur];
}

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1, 0);
    for (int i = 1; i <= N; i++) {
        ll sum = (N - 1) * 2;
        for (auto &x : adj[i]) {
            if (dp[x] > dp[i]) sum += (N - dp[i]) * (dp[i] - 1);
            else sum += ((N - 1) - dp[x]) * dp[x];
        }
        cout << sum << endl;
    }
    return 0;
}