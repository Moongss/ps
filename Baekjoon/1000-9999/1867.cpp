#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, K;
int A[501], B[501];
vector<int> adj[501];
bool visited[501];

bool solve(int cur) {
    visited[cur] = true;

    for (auto &nxt : adj[cur]) {
        if (B[nxt] == -1 || (!visited[B[nxt]] && solve(B[nxt]))) {
            B[nxt] = cur;
            A[cur] = nxt;
            return true;
        }
    }
    return false;
}
int main() {
    fastio;
    
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    int result = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        if (solve(i)) result++;
    }
    cout << result << endl;
    return 0;
}