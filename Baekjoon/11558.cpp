#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int T, N;
int adj[10001];
bool visited[10001];

int solve() {
    int result = 0;
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == N) return result;
        if (visited[adj[cur]]) return 0;

        result++;
        visited[adj[cur]] = true;
        q.push(adj[cur]);
    }
    return result;
}
int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            int x; cin >> x; 
            adj[i] = x;
        }

        cout << solve() << endl;
    }
    return 0;
}