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
int sa[1010101], pos[1010101], tmp[1010101], lcp[1010101];
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
    
    cin >> N >> s;
    solve();

    int l, r;
    l = r = -1;

    bool f = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0' && l == -1) {
            l = i;
        }
        else {
            f = true;
        }
    }
    if (l == -1 || !f) {
        cout << "0 0" << endl;
        return 0;
    }

    int posmax = 0;
    for (int i = l; i < s.length(); i++) {
        posmax = max(posmax, pos[i]);
        // cout << pos[i] << endl;
    }

    // cout << "posmax : " << s.length() - sa[posmax] << endl;
    // 무조건 s[l:] > s[sa[posmax]:]이 성립함.

    // 최대 접미사의 길이가 나오니까, sa[posmax] - l만큼 빼서 출력?
    // if (l + s.length() - sa[posmax] >= s.length()) {
    //     cout << l << " " << s.length() - l<< endl;
    //     return 0;
    // } else {
        cout << l << " " << sa[posmax]-l<< endl;
    // }


    return 0;
}