#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, M;
vector<int> adj[501];
int visited[501];

int bfs(int cur) {
    int result = 0;

    visited[cur] = true;
    queue<pii> q;
    q.push({cur, 0});
    while (!q.empty()) {
        auto elem = q.front(); q.pop();
        result++;

        if (elem.second == 2) continue;
        for (auto &x : adj[elem.first]) {
            if (!visited[x] && elem.second < 2) {
                visited[x] = true;
                q.push({x, elem.second + 1});
            }
        }
    }
    return result - 1;
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << bfs(1)  << endl;
    return 0;
}