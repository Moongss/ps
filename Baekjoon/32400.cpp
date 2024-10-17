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

int main() {
    fastio;
    
    int arr[20]; int sum = 0; int idx = 0;
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] == 20) idx = i;
    }

    sum *= 3;

    int tmp = 20;
    tmp += arr[(idx + 19) % 20] + arr[(idx + 1) % 20];
    tmp *= 20;

    if (sum == tmp) cout << "Tie" << endl;
    else if (sum > tmp) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    return 0;
}