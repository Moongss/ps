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

map<string, ll> common;
map<string, ll> special;
set<string> s;

int main() {
    fastio;

    int A, B, C; cin >> A >> B >> C;
    for (int i = 0; i < A; i++) {
        string s; ll x; cin >> s >> x;
        common[s] = x;
    }
    for (int i = 0; i < B; i++) {
        string s; ll x; cin >> s >> x;
        special[s] = x;
    }
    for (int i = 0; i < C; i++) {
        string x; cin >> x; s.insert(x);
    }

    int N; cin >> N;

    ll csum = 0;
    ll ssum = 0;
    ll scnt = 0;
    for (int i = 0; i < N; i++) {
        string menu; cin >> menu;
        if (common.find(menu) != common.end()) {
            csum += common[menu];
            continue;
        }
        else if (special.find(menu) != special.end()) {
            ssum += special[menu];
            continue;
        } 
        else if (s.find(menu) != s.end()) {
            scnt++;
        } else {
            // no case
        }
    }

    if (ssum && csum < 20000 ||
        scnt && csum + ssum < 50000 ||
        scnt > 1) {
        cout << "No"<< endl;
    } else {
        cout << "Okay" << endl;
    }
    return 0;
}