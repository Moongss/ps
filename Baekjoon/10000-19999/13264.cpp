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

string s;
int pos[101010], sa[101010], tmp[101010];
int d, n;

bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i+=d; j+=d;
    return (i < n && j < n) ? (pos[i] < pos[j]) : (i > j);
}

void init() {
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }

    d = 1;
    while (d <= n) {
        sort(sa, sa + n, cmp);

        memset(tmp, 0, sizeof(tmp));
        for (int i = 1; i < n; i++) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
        for (int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
        d *= 2;
    }
}

int main() {
    fastio;
    cin >> s; n = s.length();
    init();

    for (int i = 0; i < n; i++) {
        cout << sa[i] << endl;
    }
    return 0;
}