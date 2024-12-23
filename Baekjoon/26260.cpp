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
#define sz(v) (int)v.size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, target;
vector<int> v;

void solve(int s, int e) {
    int mid = (s + e) / 2;
    // cout << "s : " << s << ", e : "<< e << endl;
    if (s > e) return;
    solve(s, mid - 1);
    solve(mid + 1, e);
    cout << v[mid] << " ";
}

int main() {
    fastio;
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        if (v[i] == -1) target = i;
    }
    cin >> v[target];

    sort(all(v));

    solve(1, N);
    return 0;
}