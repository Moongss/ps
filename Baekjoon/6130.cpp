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

int main() {
    fastio;
    
    int N; cin >> N;
    vector<int> v(N);
    vector<int> vv(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    copy(all(v), vv.begin());

    int cnt[4];

    cnt[1] = count(all(v), 1);
    int i = 0;
    int ans = 0;
    while (i < N && v[i] == 1) i++;
    for (int j = i; j < N; j++) {
        if (v[j] == 1) swap(v[i], v[j]), ans++, i++;
    }
    // for (auto x : v) cout << x << " "; cout << endl;
    
    while (i < N && v[i] == 2) i++;
    for (int j = i; j < N; j++) {
        if (v[j] == 2 && N-cnt[3] > j) continue;
        if (v[j] == 2) swap(v[i], v[j]), ans++, i++;
    }
    // for (auto x : v) cout << x << " ";  cout << endl;


    cnt[1] = count(all(vv), 1);
    i = N-1;
    int ans2 = 0;
    while (i >= 0 && vv[i] == 3) i--;
    for (int j = i; j >= 0; j--) {
        if (vv[j] == 3) swap(vv[i], vv[j]), ans2++, i--;
    }

    while (i >= 0 && vv[i] == 2) i--;
    for (int j = i; j >= 0; j--) {
        if (vv[j] == 2 && cnt[1] < j) continue;
        if (vv[j] == 2) swap(vv[i], vv[j]), ans2++, i--;
    }
    
    cout << min(ans, ans2) << endl;
    return 0;
}