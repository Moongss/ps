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

int arr[4][4];
string s;

bool solve() {
    for (int i = 1; i <= 3; i++) {
        if (arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3] && arr[i][1] != 0) {
            return true;
        }
        if (arr[1][i] == arr[2][i] && arr[2][i] == arr[3][i] && arr[1][i] != 0) {
            return true;
        }
    }

    if (arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3] && arr[1][1] != 0) {
        return true;
    }
    if (arr[1][3] == arr[2][2] && arr[2][2] == arr[3][1] && arr[1][3] != 0) {
        return true;
    }
    return false;
}
int main() {
    fastio;
    
    int first; cin >> first;
    if (first == 1) s = "121212121"; else s = "212121212";

    for (int i = 0; i < 9; i++) {
        int x = s[i] - '0';
        int r, c; cin >> r >> c;
        arr[r][c] = x;

        if (solve()) {
            cout << x << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}