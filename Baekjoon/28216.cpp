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

int cnt[3];
int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        char ch; cin >> ch;
        if (ch == 'U') cnt[0]++;
        if (ch == 'R') cnt[1]++;
        if (ch == 'X') cnt[2]++;
    }

    int M; cin >> M;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        x--; y--;

        int tmp = min(x, y);
        if (tmp < cnt[2]) {
            x -= tmp;
            y -= tmp;
        } else {
            x -= cnt[2];
            y -= cnt[2];
        }

        if (y <= cnt[0] && x <= cnt[1]) ans++;
    }
    cout << ans << endl;
    return 0;
}