#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
vector<int> adj[200001];
int tmp[200001];
int color[200001];
int visited[200001];

int dfs(int cur, int toPaint) {
    int cnt = 0;
    visited[cur] = true;
    for (auto &nxt : adj[cur]) {
        if (!visited[nxt]) {
            cnt += (toPaint != color[nxt]);
            cnt += dfs(nxt, color[nxt]);
        }
    }
    return cnt;
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> color[i];
    }
    for (int i = 1; i < N; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cout << dfs(1, color[1]) + (color[1] > 0) << endl;
    return 0;
}