#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int dp[501][501];
vector<pair<int, pair<short, short>>> adj[501];
priority_queue<pair<int, pair<short, short>>, 
            vector<pair<int, pair<short, short>>>,
            greater<pair<int, pair<short, short>>>> pq;

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
            dp[i][j] = 0x3f3f3f3f;

    pq.push({0, {1, 0}});
    dp[1][0] = 0;
    while (!pq.empty()) {
        int curTime = pq.top().first;
        int cur = pq.top().second.first;
        int curK = pq.top().second.second;
        pq.pop();

        if (curTime > dp[cur][curK]) continue;
        for (auto &edge : adj[cur]) {
            int next = edge.first;
            int t = edge.second.first;
            int g = edge.second.second;

            // 바로 탑승
            if (curK < K && dp[next][curK + 1] > curTime + t && dp[next][curK] > curTime + t) {
                dp[next][curK + 1] = curTime + t;
                pq.push({dp[next][curK + 1], {next, curK + 1}});
            }

            // 기다리고 탑승
            int waitTime = ((curTime + g - 1) / g) * g;
            if (dp[next][curK] > waitTime + t && (curK == 0 || dp[next][curK - 1] > waitTime + t)) {
                dp[next][curK] = waitTime + t;
                pq.push({dp[next][curK], {next, curK}});
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dp[N][i]);
    }

    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
    return 0;
}