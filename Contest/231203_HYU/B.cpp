#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

ll dp[505][505];
vector<pair<int, pair<int, int>>> adj[505];
priority_queue<pair<ll, pair<int, int>>, 
            vector<pair<ll, pair<int, int>>>,
            greater<pair<ll, pair<int, int>>>> pq;

int main() {
    fastio;

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int s, e, t, g;
        cin >> s >> e >> t >> g;
        adj[s].push_back({e, {t, g}});
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dp[i][j] = 1e18;

    pq.push({0, {1, 0}});
    dp[1][0] = 0;
    while (!pq.empty()) {
        ll curTime = pq.top().first;
        int cur = pq.top().second.first;
        int curK = pq.top().second.second;
        pq.pop();

        if (curTime > dp[cur][curK]) continue;
        for (auto &edge : adj[cur]) {
            int next = edge.first;
            ll t = edge.second.first;
            ll g = edge.second.second;

            // 바로 탑승
            if (curK < K && dp[next][curK + 1] > curTime + t) {
                dp[next][curK + 1] = curTime + t;
                pq.push({dp[next][curK + 1], {next, curK + 1}});
            }

            // 기다리고 탑승
            ll waitTime = ((curTime + g - 1) / g) * g;
            if (dp[next][curK] > waitTime + t) {
                dp[next][curK] = waitTime + t;
                pq.push({dp[next][curK], {next, curK}});
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dp[N][i]);
    }

    cout << (ans == 1e18 ? -1 : ans) << endl;
    return 0;
}