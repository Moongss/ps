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
    string s; int i;

    bool operator<(const Query& q) const {
        return s < q.s;
    }
};

vector<Query> v;
vector<string> vv;

int main() {
    fastio;
    
    int N; cin >> N; cin.ignore();

    for (int k = 0; k < N; k++) {
        string s; getline(cin, s);
        vv.push_back(s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                v.push_back({s.substr(i), k});
                break;
            }
        }
    }
    sort(all(v));

    for (auto &q : v) {
        cout << vv[q.i] << endl;
    }
    return 0;
}