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

int A, B, N, M;

int visited[101010];

bool valid(int x) {
    return x >= 0 && x <= 100000;
}
void solve(int cur, int depth) {
    queue<pii> q;
    q.push({cur, depth});

    visited[cur] = depth;
    while (!q.empty()) {
        auto [cur, depth] = q.front(); q.pop();
        if (cur == M) return;
        if (visited[cur] < depth) continue;
        if (valid(cur+1) && visited[cur+1] > depth + 1) visited[cur+1] = depth + 1, q.push({cur+1, depth+1});
        if (valid(cur+A) && visited[cur+A]> depth + 1) visited[cur+A] = depth + 1, q.push({cur+A, depth+1});
        if (valid(cur+B) && visited[cur+B]> depth + 1) visited[cur+B] = depth + 1, q.push({cur+B, depth+1});
        if (valid(cur*A) && visited[cur*A]> depth + 1) visited[cur*A] = depth + 1, q.push({cur*A, depth+1});
        if (valid(cur*B) && visited[cur*B]> depth + 1) visited[cur*B] = depth + 1, q.push({cur*B, depth+1});
        if (valid(cur-1) && visited[cur-1]> depth + 1) visited[cur-1] = depth + 1, q.push({cur-1, depth+1});
        if (valid(cur-A) && visited[cur-A]> depth + 1) visited[cur-A] = depth + 1, q.push({cur-A, depth+1});
        if (valid(cur-B) && visited[cur-B]> depth + 1) visited[cur-B] = depth + 1, q.push({cur-B, depth+1});
    }
}
int main() {
    fastio;
    
    cin >> A >> B >> N >> M;
    for (int i = 0; i <= 100000; i++)
        visited[i] = 42424242;
    solve(N, 0);
    cout << visited[M] << endl;
    return 0;
}