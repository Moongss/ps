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

struct Query {
    string s;
    int i, d;

    Query(string s, int i, int d):
    s(s), i(i), d(d) {

    }

    bool operator<(const Query &q) {
        return this->i < q.i;
    }
};

vector<Query> v;

int main() {
    fastio;
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        string s; int b, c; cin >> s >> b >> c;
        v.push_back({s, b, c});
    }

    sort(all(v));
    for (auto &e : v) {
        if (isalpha(e.s[e.d-1])) cout << (char)toupper(e.s[e.d-1]);
        else cout << e.s[e.d-1];
    }
    cout << endl;
    return 0;
}