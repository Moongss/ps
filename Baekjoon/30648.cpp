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

int arr[1010][1010];
int N, a, b;
int main() {
    fastio;

    cin >> a >> b;
    cin >> N;
    arr[a][b] = 1;
    int cnt = 0;
    while (1) {
        if (a + 1 + b + 1 < N) {
            a++; b++;
        } else {
            a/=2; b/=2;
        }

        cnt++;
        if (arr[a][b]) {
            cout << cnt << endl;
            return 0;
        }
        arr[a][b]++;
    }
    return 0;
}