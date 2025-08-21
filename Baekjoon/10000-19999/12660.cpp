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

ll dp[20];
// welcome to code jam;
int main() {
    fastio;
    
    int N; cin >> N; cin.ignore();
    for (int i = 1; i <= N; i++) {
        ll ret = 0;
        memset(dp, 0, sizeof(dp));
        string str;
        getline(cin, str);

        for (auto &c : str) {
            if (c == 'w') dp[0]++;
            if (c == 'e') dp[1] += dp[0], dp[6] += dp[5], dp[14] += dp[13];
            if (c == 'l') dp[2] += dp[1];
            if (c == 'c') dp[3] += dp[2], dp[11] += dp[10];
            if (c == 'o') dp[4] += dp[3], dp[9] += dp[8], dp[12] += dp[11];
            if (c == 'm') dp[5] += dp[4], dp[18] += dp[17]; 
            if (c == ' ') dp[7] += dp[6], dp[10] += dp[9], dp[15] += dp[14];
            if (c == 't') dp[8] += dp[7];
            if (c == 'd') dp[13] += dp[12];
            if (c == 'j') dp[16] += dp[15];
            if (c == 'a') dp[17] += dp[16];

            for (int i = 0; i < 19; i++) {
                dp[i] %= 10000;
            }
        }
        // for (int i = 0; i < 19; i++) {
        //     cout << dp[i] << endl;
        // }
        ret = dp[18] % 10000;
        cout << "Case #" << i << ": ";
        int x = 4 - to_string(ret).size();
        while (x-- > 0) cout << 0;
        cout << ret << endl;
    }
    return 0;
}