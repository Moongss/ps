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

ll N;
string s;
int sa[101010], pos[101010], tmp[101010], lcp[101010];
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

ll ret = 0;
void getret() {
    stack<pll> st;
    for (ll i = 0; i < N; i++) {
        bool f = false;
        int prv;
        while (!st.empty() && lcp[st.top().y] >= lcp[i]) {
            auto [len, idx] = st.top(); st.pop();
            // cout << "i : " << i << ", ni len : "<< len << ", idx :" << idx << " ";

            if (!f) {
                ret = max(ret, len * (i - idx));
                f = !f;
                // cout << endl;
            } else {
                ret = max(ret, prv * (i - idx));
                // cout << "prv : " << prv << ", ret : " << ret << endl;
            }
            prv = lcp[idx];
        }
        st.push({N-sa[i], i});
    }

    bool f = false;
    int prv;
    while (!st.empty()) {
        auto [len, idx] = st.top(); st.pop();
        if (!f) {
            ret = max(ret, len * (N - idx));
            f = !f;
        } else {
            ret = max(ret, prv * (N - idx));
        }
        prv = lcp[idx];
    }
}

int main() {
    fastio;
    
    cin >> s; N = s.length();
    solve(); getret();
    // cout << max(ret, N) << endl;
    // for (int i =0; i < N; i++) cout << s.substr(sa[i]) << " "; cout << endl;
    // for (int i =0; i < N; i++) cout << sa[i] << " "; cout << endl;
    // for (int i =0; i < N; i++) cout << lcp[i] << " "; cout << endl;

    reverse(all(s));
    solve(); getret();
    cout << max(ret, N) << endl;
    // for (int i =0; i < N; i++) cout << s.substr(sa[i]) << " "; cout << endl;
    // for (int i =0; i < N; i++) cout << sa[i] << " "; cout << endl;
    // for (int i =0; i < N; i++) cout << lcp[i] << " "; cout << endl;
    return 0;
}