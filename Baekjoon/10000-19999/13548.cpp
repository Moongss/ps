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
    int l, r, i;
    bool operator<(const Query &o) const {
        if (l / sqrtN != o.l / sqrtN) return l < o.l;
        return r < o.r;
    }
};

int N;
int arr[101010];
int cnt[101010];
int cnt2[101010];
int ans[101010];
Query q[101010];

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sqrtN = sqrt(N);

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        q[i] = {l, r, i};
    }
    sort(q, q + Q);

    int Max = 0;
    cnt2[0] = N;
    for (int i = q[0].l; i <= q[0].r; i++) {
        cnt2[cnt[arr[i]]]--; //카운트의 카운트..? 맞나 하
        cnt[arr[i]]++;
        cnt2[cnt[arr[i]]]++;
        Max = max(Max, cnt[arr[i]]);
    }
    ans[q[0].i] = Max;
    // cout << "MAX CNT" << endl;
    // for (int i = 0; i < 10; i++) {
    //     cout << cnt2[i] << " ";
    // } cout << endl;
    // cout << "Max : " << Max << endl;

    int l = q[0].l, r = q[0].r;
    for (int i = 1; i < Q; i++) {
        // cout << "q : " << q[i].l << " " << q[i].r << " / prev : " << l << " " << r << endl;
        while (q[i].l > l) {
            cnt2[cnt[arr[l]]]--;   
            while (cnt2[Max] == 0) Max--; 
            // if (cnt[arr[l]] == Max && cnt2[cnt[arr[l]]] == 0) Max--;
            cnt[arr[l]]--;
            cnt2[cnt[arr[l]]]++;
            l++; // 순서?
        }
        while (q[i].l < l) {
            l--;
            cnt2[cnt[arr[l]]]--;
            cnt[arr[l]]++;
            cnt2[cnt[arr[l]]]++;
            
            Max = max(Max, cnt[arr[l]]); 
        }
        while (q[i].r < r) {
            cnt2[cnt[arr[r]]]--;
            // while (cnt2[Max] <= 0 && Max > 0) Max--; 
            while (cnt2[Max] == 0) Max--; 
            // if (cnt[arr[r]] == Max && cnt2[cnt[arr[r]]] == 0) Max--;
            cnt[arr[r]]--;
            cnt2[cnt[arr[r]]]++;
            r--;
        }
        while (q[i].r > r) {
            r++;
            cnt2[cnt[arr[r]]]--;
            cnt[arr[r]]++; // 이거안해줌
            cnt2[cnt[arr[r]]]++;
            
            Max = max(Max, cnt[arr[r]]); 
        }

        // cout << "MAX CNT" << endl;
        // for (int i = 0; i < 10; i++) {
        //     cout << cnt2[i] << " ";
        // } cout << endl;
        // cout << "Max : " << Max << endl;
        ans[q[i].i] = Max;
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << endl;
    return 0;
}