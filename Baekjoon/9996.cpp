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

int N;
string target;
int main() {
    fastio;
    
    cin >> N >> target;

    int a = target.find('*');
    
    string prefix, suffix;
    prefix = target.substr(0, a);
    suffix = target.substr(a + 1);

    for (int i = 0; i < N; i++) {
        string str; cin >> str;

        if (str.length() < prefix.length() + suffix.length()) {cout << "NE" << endl; continue;}

        bool f = true;
        for (int j = 0, k = 0; j < prefix.length() && f; j++, k++) {
            if (prefix[j] != str[k]) f = false;
        }
        for (int j = suffix.length() - 1, k = str.length() - 1; j >= 0 && f; j--, k--) {
            if (suffix[j] != str[k]) f = false;
        }

        cout << (f ? "DA" : "NE") << endl;
    }
}