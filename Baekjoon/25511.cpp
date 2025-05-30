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

int n, k;
vector<int> adj[101010];
bool visited[101010];
int arr[101010];

int depth;
void dfs(int cur) {
    if (arr[cur] == k) {
        cout << depth << endl;
        exit(0);
    }

    visited[cur] = true;
    for (auto &nxt : adj[cur]) {
        if (!visited[nxt]) {
            depth++;
            dfs(nxt);
            depth--;
        } 
    }
}

int main() {
    fastio;
    
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dfs(0);
    return 0;
}