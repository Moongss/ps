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

string A, B;
int dp[4040][4040];
int hik[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int main() {
    // fastio;
    
    cin >> A >> B;
    for (int i = 1; i <= A.length(); i++) {
        dp[0][i * 2 - 1] = hik[A[i-1]-'A'];
        dp[0][i * 2] = hik[B[i-1] - 'A'];
    }

    int len = A.length() * 2;
    for (int i = 1; i < len; i++) {
        for (int j = 1; j <= len - i; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % 10;
        }
    }
    cout << dp[len-2][1] << dp[len-2][2] << endl;
    return 0;
}