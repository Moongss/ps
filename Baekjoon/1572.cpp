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

ordered_mset os;

void m_erase(int val) {
    auto it = os.find_by_order(os.order_of_key(val));
    if (it != os.end() && *it == val) os.erase(it);
}

int arr[250001];
int main() {
    fastio;
    
    int N, K; cin >> N >> K;
    int mid = (1 + K) / 2;
    ll sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        os.insert(arr[i]);
        if (i >= K) {
            auto m = os.find_by_order(mid - 1);
            sum += *m;
            m_erase(arr[i - K + 1]);
        }
    }
    cout << sum << endl;
    return 0;
}