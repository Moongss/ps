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

int N, Q;
vector<pll> v;
vector<ll> T, S;
ll R[202020];
ll ret[202020];
int main() {
    fastio;
    
    cin >> N >> Q;
    T.resize(N); S.resize(N);
    for (int i = 0; i < N; i++ ) cin >> T[i];
    for (int i = 0; i < N; i++ ) cin >> S[i];
    for (int i = 0; i < N; i++) v.push_back({T[i], S[i]});
    sort(all(v));

    int Max = 0;
    for (int i = N-1; i >= 0; i--) {
        if (v[i].y > Max) R[i] = 1, Max = v[i].y;
        else if (v[i].y == Max) R[i] = R[i+1] + 1;
        else R[i] = R[i+1];
    }

    for (int i = 0; i < N; i++) T[i] = v[i].x, S[i] = v[i].y;
    while (Q--) {
        int q; cin >> q;
        int it = lower(T, q);
        cout << R[it] << endl;
    }
    return 0;
}