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
string s, a, b;
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

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        cin >> N >> a;
        s = a+a; N *= 2;
        solve();

        int ret = 424242; bool f = false;
        for (int i = 0; i < N; i++) {
            if (f) {
                // 길이순이라 어차피 뒤가 더 짧은 idx일거 같은데 반례가 있나.. 
                // -> sa[i] < N/2로 한게 에러
                if (sa[i] < ret) ret = sa[i]; 
                else break;
            }
            if (sa[i] < N/2) {
                ret = sa[i]; 
                f = true;
            }
        }

        cout << ret << endl;
    }
    return 0;
}

// "baabaabaabaa"
// "aabaabaabaa" -> 1
// "abaabaabaa" -> 2
// "baabaabaa" -> 0
// "aabaabaa" -> 1
// "abaabaa" -> 6
// 구하고 kmp?
