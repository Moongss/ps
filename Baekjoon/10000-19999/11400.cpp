#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int V, E;
int visitcnt = 0;
int visited[100001];
vector<int> adj[100001];
vector<pair<ll, ll> > result;

int solve(int cur, int prev) {
    visited[cur] = ++visitcnt;
    int minNode = visited[cur];

    for (int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (next == prev) continue;
        if (visited[next]) {minNode = min(minNode, visited[next]); continue;}

        int tmp = solve(next, cur);
        if (tmp > visited[cur])
            result.push_back({min(cur, next), max(cur, next)});
        minNode = min(minNode, tmp);
    }
    return minNode;
}
int main() {
    fastio;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    solve(1, 0);
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto &elem: result) {
        cout << elem.first << " " << elem.second << endl;
    }
    return 0;
}