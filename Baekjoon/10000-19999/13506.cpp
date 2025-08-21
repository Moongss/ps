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

int fail[1010101];
string s;

void init() {
    int N = s.size();
    for (int i = 1, j = 0; i < N; i++) {
        while (j && s[i] != s[j]) j = fail[j-1];
        if (s[i] == s[j]) fail[i] = ++j;
    }
}

bool check(int len) {
    int N = s.size();
    for (int i = 1; i < N-1; i++) {
        if (fail[i] == len) return true;
    }
    return false;
}

int main() {
    fastio;
    cin >> s; init();

    int ans = fail[s.size()-1];
    bool find = false;
    while (true) {
        if (ans == 0) break;
        if (check(ans)) {find = true; break;}
        ans = fail[ans-1];
    }
    cout << (find ? s.substr(0, ans) : "-1") << endl;
    return 0;
}