#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int dp[501];
vector<pair<int, pair<short, short>>> adj[501];
priority_queue<pair<int, pair<short, short>>, 
            vector<pair<int, pair<short, short>>>> pq;

int main() {
    fastio;
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int s, e, t, g;
        cin >> s >> e >> t >> g;
        adj[s].push_back({e, {t, g}});
    }

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    pq.push({0, {1, 0}});
    dp[1] = 0;
    while (!pq.empty()) {
        int curTime = pq.top().first;
        int cur = pq.top().second.first;
        int curK = pq.top().second.second;
        pq.pop();

        if (cur == N) continue;
        if (curTime > dp[cur]) continue;
        for (auto &edge : adj[cur]) {
            int next = edge.first;
            int t = edge.second.first;
            int g = edge.second.second;

            int waitTime = ((dp[cur] + g - 1) / g) * g;
            if (dp[next] > waitTime + t) {
                dp[next] = waitTime + t;
                pq.push({dp[next], {next, curK}});
            }

            if (curK < K && dp[next] > dp[cur] + t) { //if waitTime == 0, don't run this code
                dp[next] = dp[cur] + t;
                pq.push({dp[next], {next, curK + 1}});
            }
        }
    }

    cout << (dp[N] == 0x3f3f3f3f ? -1 : dp[N]) << endl;
    return 0;
}