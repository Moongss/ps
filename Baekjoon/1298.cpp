#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int A[101], B[101];
bool visited[101];
vector<int> adj[101];

bool dfs(int cur) {
    visited[cur] = true;

    for (auto &nxt : adj[cur]) {
        if (B[nxt] == -1 || (!visited[B[nxt]] && dfs(B[nxt]))) {
            B[nxt] = cur;
            A[cur] = nxt;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    int result = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) result++;
    }
    cout << result << endl;
    return 0;
}