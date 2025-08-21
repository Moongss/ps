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

int N, K;
vector<int> v;
int main() {
    fastio;
    cin >> N >> K;
    v.resize(N); for (auto &x : v) cin >> x;

    int cnt = 0;
    for (int i = N - 1; i >= 1; i--) {
        int max = -1;
        int t = -1;
        for (int j = 0; j <= i; j++) {
            if (max < v[j]) {
                max = v[j];
                t = j;
            }
        }
        if (i != t) {
            swap(v[i], v[t]);
            cnt++;
        }

        if (cnt == K) {
            for (auto &i : v) cout << i << " ";
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}