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

int N, Q; 
vector<int> Rv, Bv;

int main() {
    fastio;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        char ch; cin >> ch;
        if (ch == 'R') Rv.push_back(i);
        if (ch == 'B') Bv.push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        int s, e; cin >> s >> e;
        
        int a = lower(Rv, s);
        if (a == Rv.size()) {cout << -1 << endl; continue;}
        int b = lower(Rv, Rv[a] + 1);
        if (b == Rv.size()) {cout << -1 << endl; continue;}
        int c = lower(Bv, Rv[b] + 1);
        if (c == Bv.size()) {cout << -1 << endl; continue;}
        int d = lower(Bv, Bv[c] + 1);
        if (d == Bv.size() || Bv[d] > e) {cout << -1 << endl; continue;}
        cout << Rv[a] << " " << Rv[b] << " " << Bv[c] << " " << Bv[d] << endl;
    }
    return 0;
}