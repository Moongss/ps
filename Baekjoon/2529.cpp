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

int N; 
char cv[10];
bool checked[10];

pair<string, string> ret = {"0000000000", "9999999999"};

void solve(int idx, string num) {
    if (idx > N) {
        ret.x = max(ret.x, num);
        ret.y = min(ret.y, num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (checked[i]) continue;
        if (idx == 0 || (cv[idx-1] == '<' && i > num[idx-1]-'0' ) || (cv[idx-1] == '>' && i < num[idx-1]-'0')) {
            checked[i] = true;
            solve(idx+1, num + to_string(i));
            checked[i] = false;
        }
    }
}
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i <N; i++) cin >> cv[i];

    solve(0, "");
    cout << ret.x << endl;
    cout << ret.y << endl;
    return 0;
}   