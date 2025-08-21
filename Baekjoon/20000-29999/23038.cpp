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

ll MOD = 1e9+7;
int N, M, K;
ll arr[1010][1010];
bool v[1010][1010];

int main() {
    fastio;
    
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        v[x][y] = true;
    }

    arr[1][1] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            ll sum = 0;
            if (i == 1 && j == 1) continue;
            if (v[j][i]) {
                arr[j][i] = 0;
                continue;
            }
            
            if (i % 2) 
                arr[j][i] = (arr[j][i-1]+arr[j-1][i-1]+arr[j-1][i]) % MOD;
            else 
                arr[j][i] = (arr[j-1][i]+arr[j][i-1]+arr[j+1][i-1]) % MOD;
        }
    }

    cout << arr[N][M] << endl;
    return 0;
}