#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int A[201], B[201];
int a[201], b[201];
bool visited[201];
vector<int> adj[201];

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
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= M; i++) cin >> b[i];
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if ((a[i] <= 2 * b[j] && 4 * b[j] <= 3 * a[i]) || 
                (a[i] <= b[j] && 4 * b[j] <= 5 * a[i]))
                adj[i].push_back(j);
        }
    }
    
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int total = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        if (solve(i)) total++;
    }
    cout << total << endl;
    return 0;
}