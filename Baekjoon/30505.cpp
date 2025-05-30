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

int in[101010], out[101010];
int main() {
    fastio;
    
    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; // a <- b;
        in[a]++;
        out[b]++;
    }

    int K ;cin >> K;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i == K) continue;
        if (!out[i]) ans++;
    }

    if (ans + in[K] == 1) cout << "NOJAM" << endl;
    else cout << ans + in[K] << endl;
    return 0;
}