#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M, K1, K2;
int A[301], B[301];
bool visited[301];
vector<int> adj[301];

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

int solve(int K) {
    for (int i = 0; i <= 300; i++) adj[i].clear();
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    int trollCnt = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) trollCnt++;
    }
    return trollCnt;
}

int main() {
    fastio;
    
    cin >> N >> M >> K1 >> K2;
    int team1 = solve(K1);
    int team2 = solve(K2);

    cout << (team1 >= team2 ? "그만 알아보자" : "네 다음 힐딱이") << endl;
    return 0;
}