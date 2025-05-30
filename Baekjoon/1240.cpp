#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;

vector<pii> adj[1010];
bool visited[1010];

int sum = 0;
int s, e; 
void dfs(int cur) {
    if (cur == e) {
        cout << sum << endl;
        return;
    }
    for (auto [nxt, v]: adj[cur]) {
        if (visited[nxt]) continue;
        visited[nxt] = 1, sum += v;
        dfs(nxt);
        visited[nxt] = 0, sum -= v;
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i =0; i < N-1; i++ ){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    while (M--) {
        cin >> s >> e;
        visited[s] = 1; 
        dfs(s);
        visited[s] = 0;
    }
    return 0;
}