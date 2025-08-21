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

int T; 
int arr[202020];
int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) cin >> arr[i];

        bool f = true;
        if (arr[0] == 1 && N == 1) {cout << "YES" << endl; continue;}
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] <= arr[i + 1]) {
                arr[i + 1] -= arr[i] - 1;
                arr[i] = 0;
            }
            else {
                arr[i]--;
            }
            // else {break;}
            //     cout << "NO" << endl;
            //     break;
            // }
        }

        for (int i = 0; i < N; i++) {
            if (arr[i] && i < N - 2 || (N > 1 && arr[N - 2] > 1 || arr[N - 1] > 1)) {
                f = false;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}