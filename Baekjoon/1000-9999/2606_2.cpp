#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;
bool visited[101];
vector<int> v[101];

int ans = 0;
void solve(int cur) {
    if (cur != 1) ans++;
    visited[cur] = true;
    for (auto &nxt : v[cur]) {
        if (visited[nxt]) continue;
        
        visited[nxt] = true;
        solve(nxt);
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1);
    cout << ans << endl;
    return 0;
}