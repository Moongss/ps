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
    
    int N, r1, c1, r2, c2; cin >> N >> r1 >> c1 >> r2 >> c2;

    for (int i = 0; i < r2 - r1 + 1; i++) {
        for (int j = 0; j < c2 - c1 + 1; j++) {
            int r = (r1 + i) % (2*N - 1);
            int c = (c1 + j) % (2*N - 1);

            int pos = abs(r - (N - 1)) + abs(c - (N - 1));
            if (pos < N) 
                cout << (char)(pos % 26 + 'a');
            else
                cout << '.';
        }
        cout << endl;
    }

    return 0;
}