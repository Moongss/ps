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

int sqrtN;
struct Query {
    int i, l, r, ans;
    bool operator<(const Query &o) const {
        if (l / sqrtN != o.l / sqrtN) return l < o.l;
        return r < o.r;
    }
};

int N, M;
vector<int> v;
vector<Query> qv;

int cnt[1010101];
int ans[1010101];

int main() {
    fastio;
    
    cin >> N; v.resize(N);
    sqrtN = sqrt(N);
    for (auto &i : v) cin >> i;

    cin >> M; qv.resize(M);
    for (int i = 0; i < M; i++) {
        int l, r; cin >> l >> r; l--; r--;
        qv[i] = {i, l, r};
    }
    sort(all(qv));

    int ret = 0;
    for (int i = qv[0].l; i <= qv[0].r; i++) {
        if (cnt[v[i]]++ == 0) ret++;
    }

    qv[0].ans = ret;
    pii prv = {qv[0].l, qv[0].r};

    for (int i = 1; i < M; i++) {
        while (prv.x < qv[i].l) {
            cnt[v[prv.x]]--;
            if (cnt[v[prv.x]] == 0) ret--;
            prv.x++;
        }
        while (prv.x > qv[i].l) {
            prv.x--;
            if (cnt[v[prv.x]] == 0) ret++;
            cnt[v[prv.x]]++;
        }
        while (prv.y < qv[i].r) {
            prv.y++;
            if (cnt[v[prv.y]] == 0) ret++;
            cnt[v[prv.y]]++;
        }
        while (prv.y > qv[i].r) {
            cnt[v[prv.y]]--;
            if (cnt[v[prv.y]] == 0) ret--;
            prv.y--;
        }
        qv[i].ans = ret;
    }

    sort(all(qv), [](const Query &a, const Query &b) {
        return a.i < b.i;
    });
    for (auto &e : qv) cout << e.ans << endl;
    return 0;
}