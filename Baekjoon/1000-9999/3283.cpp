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

int N;
char arr[5][105];

int dp[2][2][105];
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<char> v; v.push_back('T');
    for (int j = 0; j < N; j++) {
        bool f = false;
        for (int i = 0; i < 5; i++) {
            if (arr[i][j] == '?') continue;
            if (arr[i][j] == 'X') {v.push_back('X'); f = true; break;}
            if (arr[i][j] == '.') {v.push_back('.'); f = true; break;}
        }
        if (!f) v.push_back('?');
    }

    // dp[앞/뒤][B/W][i = 1 ~ 100]
    for (int k = 0; k < 10000; k++) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++) {
            if (v[i] == 'X') {
                dp[0][0][i] = dp[0][0][i-1] + 1;
                dp[0][1][i] = 0;
            }
            else if (v[i] == '.') {
                dp[0][0][i] = 0;
                dp[0][1][i] = dp[0][1][i-1] + 1;
            }
        }

        for (int i = N; i >= 1; i--) {
            if (v[i] == 'X') {
                dp[1][0][i] = dp[1][0][i+1] + 1;
                dp[1][1][i] = 0;
            }
            else if (v[i] == '.') {
                dp[1][0][i] = 0;
                dp[1][1][i] = dp[1][1][i+1] + 1;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (v[i] == '?') {
                if (dp[0][0][i-1] + dp[1][0][i+1] >= 2) {
                    v[i] = '.';
                }
                else if (dp[0][1][i-1] + dp[1][1][i+1] >= 2) {
                    v[i] = 'X';
                }
                else v[i] = '?';
            }
        }
    }


    bool f = false;
    for (int i = 1; i <= N; i++) {
        if (v[i] == '?') f = true;
    }


    if (f) {
        cout << "UNDETERMINABLE" << endl;
    } else {
        v.push_back('T');//tmp
        for (int i = 1; i <= N; i++) {
            if (v[i] == v[i+1]) {cout << 1, i++;}
            else {cout << 0;}
        }
        cout << endl;
    }

    return 0;
}