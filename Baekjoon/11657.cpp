#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 987654321

using namespace std;
using ll = long long;
using ld = long double;

int N, M, A, B, C;
vector<pair<int, int>> adj[501];
ll dist[501];

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
    }

    fill(dist, dist + 501, INF);
    dist[1] = 0;

    bool isCycle = false;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 1; j <= N; j++) {
            for (auto p : adj[j]) {
                int next = p.first;
                int cost = p.second;
                if (dist[j] != INF && dist[next] > dist[j] + cost) {
                    dist[next] = dist[j] + cost;
                }
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        for (auto p : adj[j]) {
            int next = p.first;
            int cost = p.second;
            if (dist[j] != INF && dist[next] > dist[j] + cost) {
                isCycle = true;
                break;
            }
        }
    }
    
    if (!isCycle) {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) cout << -1 << endl;
            else cout << dist[i] << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}