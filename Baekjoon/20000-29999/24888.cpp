#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M;
vector<pair<int, int>> adj[200001];
vector<int> path;

ll dist[200001];
int visitLog[200001];
int noteCnt[200001];
bool note[200001];
int sumNote = 0;

int main() {
    fastio;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= N; i++) {
        cin >> note[i];
        sumNote += note[i];
        noteCnt[i] = -1;
    }
    fill(dist, dist + N + 1, LLONG_MAX);

    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    visitLog[1] = 0;
    noteCnt[1] = note[1];
    while (!pq.empty()) {
        ll cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;
        for (auto &elem : adj[cur]) {
            int nxt = elem.first;
            ll w = elem.second;
            if (dist[nxt] >= cost + w) {
                if (dist[nxt] > cost + w) {
                    dist[nxt] = cost + w;
                    pq.push({-dist[nxt], nxt});
                }
                if (noteCnt[nxt] <= noteCnt[cur] + note[nxt]) {
                    noteCnt[nxt] = noteCnt[cur] + note[nxt];
                    visitLog[nxt] = cur;
                }
            }
        }
    }

    if (noteCnt[N] == sumNote) {
        int cur = N;
        while (cur != 0) {
            path.push_back(cur);
            cur = visitLog[cur];
        }

        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}