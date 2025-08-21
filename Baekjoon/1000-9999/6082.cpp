#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int P, C, N;
vector<int> adj[30303];
bool visited[30303];
int main() {
    fastio;
    cin >> P >> C >> N;
    for (int i = 0; i < C; i++) {
        int x, y; cin >> x >> y;
        if (x == y) adj[x].push_back(y);
        else {
            adj[x].push_back(y);
            adj[y].push_back(x);    
        }
    }
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        for (auto &nxt : adj[x]) visited[nxt] = true;
    }

    // 1번부터 탐색, N에 속한게 있다? 
    if (visited[1]) {
        cout << P << endl;
        return 0;
    }

    int cnt = 1;
    queue<int> q; q.push(1); visited[1] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &nxt : adj[cur]) {
            if (visited[nxt]) continue;

            cnt++;
            visited[nxt] = true;
            q.push(nxt);
        }
    }

    cout << P - cnt << endl;
    return 0;
}