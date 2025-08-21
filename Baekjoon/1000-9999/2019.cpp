#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
map<pii, int> m;
vector<int> adj[60];
bool visited[60];

bool dfs(int cur, int prev) {
    if (adj[cur].size() != 2) return false;
    visited[cur] = true;

    for (auto &x : adj[cur]) {
        if (x == prev || visited[x]) continue;
        else return dfs(x, cur);
    }
    return true;
}

int main() {
    fastio;
    
    cin >> N;
    int nodeCnt = 0;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        if (m.find({x1, y1}) == m.end()) m[{x1, y1}] = nodeCnt++;
        if (m.find({x2, y2}) == m.end()) m[{x2, y2}] = nodeCnt++;

        int a = m[{x1, y1}];
        int b = m[{x2, y2}];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < nodeCnt; i++) {
        compress(adj[i]);
    }

    int sum = 0;
    for (int i = 0; i < nodeCnt; i++) {
        if (!visited[i] && dfs(i, -42)) {
            sum++;
        }
    }
    
    cout << sum << endl;
    return 0;
}