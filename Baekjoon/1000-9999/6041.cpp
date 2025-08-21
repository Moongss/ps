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

int main() {
    fastio;
    
    int N; cin >> N;
    vector<pair<string, pii>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y.x >> v[i].y.y;
    }

    int ret = 424242;
    for (int i = 1000; i <= 9999; i++) {
        string m = to_string(i);
        bool f = true;
        for (auto [n, t] : v) {
            auto [s, b] = t;
            int c1 = 0; int c2 = 0;

            bool ar[4] = {0, 0,0,0};
            for (int j = 0; j < 4; j++) {
                if (n[j] == m[j]) {
                    ar[j]=true;
                    c1++;
                }
            }

            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (!ar[j] && !ar[k] && j!=k && n[j] == m[k]) {
                        c2++;
                    }
                }
            }
            if (!(c1 == s && c2 == b)) {
                f = false;
                break;
            }
        }       
        if (f) {
            ret = i; 
            break;
        }
    }
    if (ret == 424242) cout << "NONE" << endl;
    else cout << ret << endl;
    return 0;
}