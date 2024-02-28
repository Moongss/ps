#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int A[1001], B[1001];
bool visited[1001];
map<string, int> m;
vector<int> adj[1001];

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
    for (int i = 1; i <= M; i++) {
        string str; cin >> str;
        m.insert({str, i});
    }

    for (int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            string name; cin >> name;
            adj[i].push_back(m[name]);
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    int result = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) result++;
    }

    if (result == N) cout << "YES" << endl;
    else cout << "NO\n" << result << endl;
    return 0;
}