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
vector<int> v;
vector<int> ret;
vector<int> v2, v3;
int main() {
    fastio;
    
    cin >> N;
    v.resize(N); ret.resize(N);
    for (auto &i : v) cin >> i;
    for (auto &i : ret) cin >> i;

    for (int i = 0; i < N * 2 - 1; i++) {
        v2.push_back(ret[i % N]);
        v3.push_back(ret[N - (i % N) - 1]);
    }

    int idx = 0;
    for (int i = 0; i < v2.size(); i++) {
        while (idx < N && i < v2.size()) {
            if (v[idx] == v2[i]) idx++; i++; 
        }
        if (idx == N) {cout << "good puzzle" << endl; return 0;}
        idx = 0;
    }
    for (int i = 0; i < v3.size(); i++) {
        while (idx < N && i < v3.size()) {
            if (v[idx] == v3[i]) idx++; i++; 
        }
        if (idx == N) {cout << "good puzzle" << endl; return 0;}
        idx = 0;
    }
    cout << "bad puzzle" << endl;
    return 0;
}