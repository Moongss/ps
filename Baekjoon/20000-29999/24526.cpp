#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int indegree[100001];
vector<int> adj[100001];

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
        indegree[a]++;
    }

    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            ans++;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                ans++;
                q.push(nxt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}