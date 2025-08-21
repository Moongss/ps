#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int visitcnt = 0;
int visited[100];
vector<int> adj[100];
vector<pair<int, int>> result;

int solve(int cur, int prev) {
    visited[cur] = ++visitcnt;
    int minNode = visited[cur];

    for (int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (next == prev) continue;
        if (!visited[next]) {
            int tmp = solve(next, cur);
            if (tmp > visited[cur])
                result.push_back({min(cur, next), max(cur, next)});
            minNode = min(minNode, tmp);
        } else {
            minNode = min(minNode, visited[next]); 
        }
    }
    return minNode;
}
int main() {
    fastio;
    
    while (true) {
        int p, c; cin >> p >> c;
        if (p == 0 && c == 0) break;

        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < p; i++) adj[i].clear();
        result.clear();

        for (int i = 0; i < c; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        solve(0, -1);
        bool f = false;
        for (int i = 0; i < p; i++) {
            if (!visited[i]) f = true;
        }
        cout << (result.size() || f ? "Yes" : "No") << endl;
    }
    return 0;
}