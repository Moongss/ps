#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define FOX 0
#define WOLF 1
#define FAST 0
#define SLOW 1

using namespace std;
using ll = long long;
using ld = long double;

int N, M, a, b, d;
vector<pair<int, int>> adj[4001];
ll dist[4001][2];
ll wDist[4001][2];
int state[4001];
int ans;

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({b, d * 2});
        adj[b].push_back({a, d * 2}); 
    }

    for (int i = 1; i <= N; i++) {
        dist[i][FOX] = dist[i][WOLF] = INT_MAX;
        wDist[i][SLOW] = wDist[i][FAST] = INT_MAX;
    }

    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    dist[1][FOX] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        ll curDist = -pq.top().first;
        pq.pop();

        if (dist[cur][FOX] < curDist) continue;
        for (auto p : adj[cur]) {
            int next = p.first;
            ll nextDist = p.second + curDist;

            if (dist[next][FOX] > nextDist) {
                dist[next][FOX] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }

    priority_queue<pair<ll, pair<int, int>>> wolfPQ;
    wolfPQ.push({0, {1, FAST}});
    wDist[1][FAST] = 0;
    while (!wolfPQ.empty()) {
        int cur = wolfPQ.top().second.first;
        int curState = wolfPQ.top().second.second;
        ll curDist = -wolfPQ.top().first;
        wolfPQ.pop();

        if (wDist[cur][curState] < curDist) continue;
        for (auto p : adj[cur]) {
            int next = p.first;
            int nextState = (curState + 1) % 2;
            ll nextDist = p.second;

            if (curState % 2 == 0) nextDist /= 2;
            else nextDist *= 2;
            nextDist += curDist;

            if (wDist[next][nextState] > nextDist) {
                wDist[next][nextState] = nextDist;
                wolfPQ.push({-nextDist, {next, nextState}});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        dist[i][WOLF] = min(wDist[i][FAST], wDist[i][SLOW]);
        if (dist[i][FOX] < dist[i][WOLF]) ans++;
    }
    cout << ans << endl;
    return 0;
}