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

ll arr[303030];
ll pre[303030];
vector<ll> tr[1201010];

void init(int s, int e, int node) {
    if (s == e) {
        tr[node].push_back(pre[s] * 2);
        return;
    }
    int m = s + e >> 1;
    init(s, m, node << 1);
    init(m+1, e, node << 1 | 1);

    vector<ll> &l = tr[node << 1];
    vector<ll> &r = tr[node << 1 | 1];

    int i = 0, j = 0;
    while (i < l.size() && j < r.size()) {
        if (l[i] < r[j]) tr[node].push_back(l[i++]);
        else tr[node].push_back(r[j++]);
    }

    while (i < l.size()) tr[node].push_back(l[i++]);
    while (j < r.size()) tr[node].push_back(r[j++]);
}

ll query(int s, int e, int l, int r, ll k, int node) {

    if (r < s || e < l) return LLONG_MAX;
    if (l <= s && e <= r) {
        // if k = 30, tr[node] = {28} -> 0
        // 아니 이러면 음수인거 못찾는데 
    
        if (tr[node].size() == 1) return tr[node].front();
        auto ret = lower_bound(all(tr[node]), k);
        // cout << "s e ret : " << s << " " << e << " " << *ret << ", prev : " << *prev(ret) << ", next : " << *next(ret) << endl;
        // 최소한 노드 1개임
        if (ret == tr[node].end()) return *prev(ret);
        if (ret == tr[node].begin()) {
            if (next(ret) != tr[node].end() && abs(*ret - k) > abs(*next(ret) - k))
                return *next(ret);
            return *ret;
        }
        // [... x]
        if (next(ret) == tr[node].end()) return (abs(*ret - k) < abs(*prev(ret) - k) ? *ret : *prev(ret));
        else { // [... x ...]
            ll a1 = abs(*ret - k);
            ll a2 = abs(*prev(ret) - k);
            ll a3 = abs(*next(ret) - k);

            ll Min = min({a1, a2, a3});
            if (Min == a1) return *ret;
            else if (Min == a2) return *prev(ret);
            else return *next(ret);
        }
    }

    int m = s + e >> 1;

    ll left = query(s, m, l, r, k, node << 1);
    ll right = query(m+1, e, l, r, k, node << 1 | 1);

    if (left == LLONG_MAX) return right;
    if (right == LLONG_MAX) return left;
    if (abs(left - k) < abs(right - k)) return left;
    else return right;

    //아니 자꾸 아래처럼해서 이상하게 결과나왔;
    // return min(query(s, m, l, r, k, node << 1), query(m+1, e, l, r, k, node << 1 | 1));
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }

    init(1, N, 1);

    cin >> Q;
    while (Q--) {

        // K: [l+k-1, l+2k-1]
        // 이 구간에.. (pre[K] - pre[l-1]) - (pre[r] - pre[K])
        // 이거 젤 작은거 구하면댐 절댓값 최소로.
        // 2 pre[K] -(pre[r] + pre[l-1]) = 0 여야함. 그래야 최소.
        // 그럼 pre[K] = (pre[r] + pre[l-1]) / 2인데 나누기 오차 있을거같음 -> 어차피 상관없

        // 그럼 pre[r] + pre[l-1]를 쿼리로 넘겨서 찾기.
        // 저거 구하기. 근데 최소 어케구함? 매번하면 N일텐데.. 이분탐색때려서, 최솟값? 매번 끌고올라와
        ll ql, qr, qk;
        cin >> ql >> qr;
        
        // k : 1/3
        // min: arr[l : l+k-1] ~ [l+k+1 ~ r]
        // max: arr[l : l + 2k-1][l + 2k ~ r]
        qk = (qr-ql+1)/3;


        ll L = ql + qk - 1;
        ll R = ql + 2 * qk - 1; 
        // cout << "L R : " << L << " " << R << endl;
        // cout << "pre[R] + pre[L-1] : " << pre[R] + pre[L-1] << endl;

        ll tmp = query(1, N, L, R, (pre[qr] + pre[ql-1]), 1);
        cout << abs(tmp - (pre[qr] + pre[ql-1])) << endl;
    }
    return 0;
}