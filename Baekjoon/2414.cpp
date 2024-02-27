#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
char board[100][100];
int A[5050], B[5050];
int a[100][100], b[100][100];
bool visited[5050];
vector<int> adj[5050];

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
    

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 1;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '*') flag = true;
            if (board[i][j] == '.' && flag) {cnt++; flag = false; continue;}

            a[i][j] = cnt;
        }
        if (flag) {cnt++; flag = false; continue;}
    }

    cnt = 1, flag = false;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[j][i] == '*') flag = true;
            if (board[j][i] == '.' && flag) {cnt++; flag = false; continue;}

            b[j][i] = cnt;
        }
        if (flag) {cnt++; flag = false; continue;}
    }

    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '*') {
                cnt = max(cnt, a[i][j]);
                adj[a[i][j]].push_back(b[i][j]);
            } 
        }
    }

    int result = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 1; i <= cnt; i++) { 
        memset(visited, false, sizeof(visited));
        if (dfs(i)) result++;
    }
    cout << result << endl;
    return 0;
}