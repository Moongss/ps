#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T, N, M;
vector<int> adj[1010];
bool visited[1010];
int R[1010];

void init() {
    for (auto &x : adj) {
        x.clear();
    }
    // for (int i = 0; i < 1010; i++) {
    //     if (adj[i].size()) cout << adj[i].size() << endl;
    // }
    memset(R, -1, sizeof(R));
    memset(visited, false, sizeof(visited));
}

bool solve(int cur) {
    visited[cur] = true;

    for (auto nxt : adj[cur]) {
        if (R[nxt] == -1 || (!visited[R[nxt]] && solve(R[nxt]))) {
            R[nxt] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        init();
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }

        int total = 0;
        for (int i = 0; i < N; i++) {
            memset(visited, false, sizeof(visited));
            if (solve(i)) total++;
        }
        cout << total << endl;
    }
    return 0;
}