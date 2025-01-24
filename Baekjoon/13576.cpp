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

string s;
int N, d;
int sa[101010], lcp[101010], tmp[101010], pos[101010], fail[101010];
int cnt[101010];

bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += d; j += d;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void init() {
    N = s.size();
    for (int i = 0; i < N; i++) sa[i] = i, pos[i] = s[i];
    for (d = 1; d <= N; d *= 2) {
        sort(sa, sa + N, cmp);
        for (int i = 0; i < N-1; i++) tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++) pos[sa[i]] = tmp[i];
        if (tmp[N-1] == N-1) break;
    }

    for (int i = 0, k = 0; i < N; i++, k = max(k-1, 0)) {
        if (pos[i] == 0) continue;
        for (int j = sa[pos[i]-1]; s[i+k] == s[j+k]; k++) {}
        lcp[pos[i]] = k;
    }

    // kmp 
    for (int i = 1, j = 0; i < N; i++) {
        while (j && s[i] != s[j]) j = fail[j-1];
        if (s[i] == s[j]) fail[i] = ++j;
    }
}

int makecnt(int cur) {
    if (cnt[cur]) return cnt[cur];
    cnt[cur] = 1;
    for (int nxt = cur+1; nxt < N; nxt++) {
        if (lcp[nxt] < N - sa[cur]) break;
        // 특정 suffix 포함하고 있는거임. (prefix-suffix)
        // tle: 앞에꺼 있네 아어케더하지
        int add = makecnt(nxt);
        cnt[cur] += add;
        nxt += add-1;
    }   
    return cnt[cur];
}

int main() {
    fastio;
    
    cin >> s; 
    init();

    // cout << "N : " << N << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << sa[i] << " " << lcp[i] << " "<< pos[i] << " " << s.substr(sa[i])  << endl;
    // }

    // for (int i =0; i < N; i++) {
    //     cout << fail[i] << " "; 
    // }cout << endl;

    for (int i = 0; i < N; i++) {
        if (!cnt[i]) makecnt(i);
    }

    int tmp = N;
    vector<pii> ret;
    while (tmp) {
        // cout << tmp << endl;
        ret.push_back({tmp, cnt[pos[N-tmp]]});
        tmp = fail[tmp-1];
    }
    reverse(all(ret));

    cout << ret.size() << endl;
    for (auto [a, b] : ret) {
        cout << a << " " << b << endl;
    }
    return 0;
}