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
int ret = 0;
string cs;

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

        // j가 더 짧음. j는 sa의 시작 포인터니 a보다 길어야함.
        // i도 마찬가지로 S[i:]을 의미하는 i이니 a보다 짧아야 함.
        // 근데 둘이 바뀔수도 있음
        
        // cout << "k : " << k << ", i , j : " << i << "< " << j << endl;
        if ((i < a.length() && j > a.length() ||
            i > a.length() && j < a.length()) && ret < k) {
            ret = k;
            cs = s.substr(sa[pos[i]], k);
        }
        k = max(k-1, 0);
    }
}

int main() {
    fastio;
    
    cin >> a >> b;
    s = a + "@" + b; 
    N = s.length();
    solve();

    cout << ret << endl << cs << endl;
    return 0;
}