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

int cnt[10101];
void solve(string n) {
    int sum = stoi(n);
    for (auto &c : n) {
        sum += c-'0';
    }
    if (sum > 10000) return;

    cnt[sum]++;
    solve(to_string(sum));
}

int main() {
    fastio;
    
    for (int i = 1; i <= 10000; i++) solve(to_string(i));
    for (int i = 1; i <= 10000; i++) {
        if (!cnt[i]) cout << i << endl;
    }

    return 0;
}