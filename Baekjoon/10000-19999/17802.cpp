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

int n, x;
int arr[21][22];
int main() {
    fastio;
    cin >> n >> x;

    if (pow(2, n-1) > x) cout << "impossible" << endl;
    else {
        arr[1][1] = x; cout << x << endl;
        for (int i = 2; i <= n; i++) {
            arr[i][1] = pow(2, n-i); cout << arr[i][1] << " ";
            for (int j = 2; j <= i; j++) {
                arr[i][j] = arr[i-1][j-1]-arr[i][j-1];
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}

// 1
// 1 1

// 33
// 17 16
// 9 8 8
// 5 4 4 4
// 3 2 2 2 2
// 2 1 1 1 1 1