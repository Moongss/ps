#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int R, C, N;
bool board[300][300];
int A[300], B[300];
bool visited[300];
vector<int> adj[300];

bool dfs(int cur) {
    visited[cur] = true;
    
    for (auto &nxt: adj[cur]) {
        if (B[nxt] == -1 || (!visited[B[nxt]] && dfs(B[nxt]))) {
            A[cur] = nxt;
            B[nxt] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    

    cin >> R >> C >> N;
    memset(board, true, sizeof(board));
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y; x--; y--;
        board[x][y] = false;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j]) adj[i].push_back(j);
        }
    }

    int result = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 0; i <= R; i++) { 
        memset(visited, false, sizeof(visited));
        if (dfs(i)) result++;
    }
    cout << result << endl;
    return 0;
}