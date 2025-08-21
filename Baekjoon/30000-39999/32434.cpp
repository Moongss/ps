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
vector<int> arr;
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
        pos[i] = arr[i];
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
        while (i+k<N && j+k<N && arr[i+k] == arr[j+k]) k++;

        lcp[pos[i]] = k;
        k = max(k-1, 0);
    }
}


int main() {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    solve();
    ll ans = 0;

    stack<pii> st; // what is monotone stack/queue ah...
    vector<pii> v(N);

    // 2번째 조건을 넣는게 중요함.. 안그러면 빠져서 구간자체가 걍 다 똑같게 됨.. 
    // 문제는 lcp가 같을때 idx를 비교할때 L->R, R->L의 조건을 똑같이 줘야한다는거임. (한쪽 기준으로 (idx작냐/크냐))
    // 그래야 성립함.. 
    for (int i = 0; i < N; i++) {
        while (!st.empty() && (st.top().x > lcp[i] || st.top().x == lcp[i] && st.top().y < i)) st.pop(); // >로 해도 됨
        if (st.empty()) v[i].x = -1; 
        else v[i].x = st.top().y;
        st.push({lcp[i], i});
    }
    while (!st.empty()) st.pop();
    for (int i = N-1; i >= 0; i--) {
        while (!st.empty() && (st.top().x > lcp[i] || st.top().x == lcp[i] && st.top().y < i)) st.pop(); // 근데 할거면 얘도 똑같이.
        if (st.empty()) v[i].y = N; 
        else v[i].y = st.top().y;
        st.push({lcp[i], i});
    }

    for (ll i = 0; i < N; i++) {
        ans += lcp[i] * (ll)(i - v[i].x) * (v[i].y - i);
    }
    ans *= 2;
    ans += N * (N+1) / 2;
    ll all = N * N;

    cout << ans / gcd(ans, all) << "/" << all / gcd(ans, all) << endl;
}