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

bool abst[1010][1010];
int main() {
    fastio;
    
    int N, K; cin >> N >> K;
    vector<pii> v; 
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y; 
        abst[y+500][x+500] = true;
    }

    int cx, cy;
    cx = cy = 500;
    while (K--) {
        char c; cin >> c;
        if (c == 'L' && !abst[cy][cx-1]) cx--;
        if (c == 'R' && !abst[cy][cx+1]) cx++;
        if (c == 'U' && !abst[cy+1][cx]) cy++;
        if (c == 'D' && !abst[cy-1][cx]) cy--;
    }
    cout << cx - 500 << " " << cy - 500 << endl;
    return 0;
} 