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
string s;
int sa[202020], pos[202020], tmp[202020], lcp[202020];
int d;

bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i+=d; j+=d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : i > j;
}

void solve() {
    // sa
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }

    d = 1;
    while (d <= N) {
        sort(sa, sa+N, cmp);
        
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < N-1; i++) {
            tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
        }
        for (int i = 0; i < N; i++) {
            pos[sa[i]] = tmp[i];
        }
        d *= 2;
    }

    // lcp
    for (int i = 0, k = 0; i < N; i++) {
        if (pos[i] == 0) continue;

        int j = sa[pos[i]-1];
        while (i+k<N && j+k<N && s[i+k] == s[j+k]) k++;

        lcp[pos[i]] = k;
        k = max(k-1, 0);
    }
}

int seg[202020 * 4]; // sum seg
void init(int s, int e, int node) {
    if (s == e) {
        seg[node] = tmp[s];
        return;
    }

    int m = s + e >> 1;
    init(s, m, node << 1);
    init(m+1, e, node << 1 | 1);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

int query(int l, int r, int s, int e, int node) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];

    int mid = s + e >> 1;
    return min(query(l, r, s, mid, node << 1), query(l, r, mid+1, e, node << 1 | 1));
}

int main() {
    fastio;
    
    cin >> s;
    queue<pii> qq;

    string tt = "";
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') {
            qq.push({1, i-cnt});
            cnt++;
        } else {
            tt += s[i];
        }
    }
    s = tt;
    N = s.length();
    solve();

    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < N; i++) {
        cout << "i : " << i << "sa[i] : " << s.substr(sa[i]) << ", lcp :" << lcp[i] << ", sa[i] : " << sa[i] << endl;
        tmp[N - sa[i]] = lcp[i];
    }
    for (int i = 1; i <= N; i++) {
        cout << "len : " << i << " lcp : " << tmp[i] << endl;
    }

    init(1, N, 1);
    while (!qq.empty()) {
        auto [l, r] = qq.front(); qq.pop();
        cout << "l : " << l << ", r : " << r << endl;
        cout << "query : " << query(l, r, 1, N, 1) << endl;
        cout << r * (r+1) / 2 - query(l, r, 1, N, 1) << endl;
    }
    return 0;
}

// i : 0sa[i] : a, lcp :0
// i : 1sa[i] : aba, lcp :1
// i : 2sa[i] : ba, lcp :0

// ababa
// i : 0sa[i] : a, lcp :0
// i : 1sa[i] : aba, lcp :1
// i : 2sa[i] : ababa, lcp :3
// i : 3sa[i] : ba, lcp :0
// i : 4sa[i] : baba, lcp :2

// i : 1sa[i] : aba, lcp :1
// i : 2sa[i] : ababa, lcp :3
// i : 4sa[i] : baba, lcp :2

// [1,3] -> [n-s+1, n-e+1] -> [3, 5] : lcp 1, 2, 3인데.. 이건 결국 기존 문자열의 정보라서 아예 성립을 안한다.
// 특정 접미사 T의 인덱스가 i라고 할때, [L, ... i ... R]의 min값이 있으면 그 구간 사이의 모든 lcp의 min값이 공통 문자열이 된다. 흠
// 문자열 길이로 segtree node에 박고 멤버로 lcp min/max를 들고 다니면서 쿼리 처리가 되나?

// 구간 똑같이 하고, 문자열 길이가 e니까 ... e * (e+1) / 2 - minquery([n-s+1, n-e+1]) 이건듯?

//abc
// i : 0sa[i] : abc, lcp :0
// i : 1sa[i] : bc, lcp :0
// i : 2sa[i] : c, lcp :0
// -> 6

// abcabc
// i : 0sa[i] : abc, lcp :0
// i : 1sa[i] : abcabc, lcp :3
// i : 2sa[i] : bc, lcp :0
// i : 3sa[i] : bcabc, lcp :2
// i : 4sa[i] : c, lcp :0
// i : 5sa[i] : cabc, lcp :1

// len : 1 2 3 4 5 6
// lcp : 0 0 0 1 2 3
// 걍 문자열 길이로 정렬하고 query날리면 틀리나? 아다리로 맞는건가 지금
