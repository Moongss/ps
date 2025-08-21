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
vector<ll> A, B;

ll bits[2][32]; //&+
pll one[2][32]; //bit별 min max 
pll zero[2][32]; //bit별 min max 

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        B.push_back(x);
    }
    sort(all(A)); sort(all(B));

    ll ans = 0; //+&
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j <= 28; j++) {
            if (A[i] & (1LL << j)) bits[0][j]++;
            if (B[i] & (1LL << j)) bits[1][j]++;
        }
    }

    // wa: 여기군
    for (ll i = 0; i <= 28; i++) {
        ans += (((bits[0][i] * bits[1][i]) % 1999) * ((1LL << i) % 1999)) % 1999;
        ans %= 1999;
    }
    cout << ans << " ";

    ans = 0;
    ll test = (1LL << 30) - 1;
    // 아 벡터에 때려박아서 쓸걸 개귀찮네진짜..
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= 29; j++) {
            one[i][j] = {test, 0};
            zero[i][j] = {test, 0};
        }
    }


    for (ll &a : A) {
        for (ll i = 0; i <= 29; i++) {
            ll k = 1LL << (i+1); k--;
            if (a & (1LL << i)) one[0][i] = {min(one[0][i].x & k, a & k), max(one[0][i].y & k, a & k)};
            else zero[0][i] = {min(zero[0][i].x & k, a & k), max(zero[0][i].y & k, a & k)};
        }
    }

    for (ll &b : B) {
        for (ll i = 0; i <= 29; i++) {
            ll k = 1LL << (i+1); k--;
            if (b & (1LL << i)) one[1][i] = {min(one[1][i].x& k, b& k), max(one[1][i].y& k, b& k)};
            else zero[1][i] = {min(zero[1][i].x& k, b& k), max(zero[1][i].y& k, b& k)};
        }
    }

    for (ll i = 0; i <= 29; i++) {
        // 0... 0...

        // cout << "00 test : " << (1LL << i) << endl;
        // cout << zero[0][i].x << " " << zero[1][i].x << " " << (zero[0][i].x + zero[1][i].x) << " " << (1 << i) << " " << ((zero[0][i].x + zero[1][i].x) & (1 << i)) << endl;
        if (zero[0][i].x != test && zero[1][i].x != test) {
            // cout << "!" << "zerox + x : " << (zero[0][i].x + zero[1][i].x) << " " << (1 << i) << " " << ((zero[0][i].x + zero[1][i].x) & (1 << i)) << endl;
            // cout << !((zero[0][i].x + zero[1][i].x) & (1LL << i)) << endl;

            // 비트 연산한거에 바로 ! 붙이면 왜 안되지? 음.. 비트로 계산하나?
            ll t = (zero[0][i].x + zero[1][i].x) & (1LL << i);
            if (!((zero[0][i].x + zero[1][i].x) & (1LL << i))) continue;
        }
        
        // 0... 1...
        // 1... 0...
        // cout << "01 test" << endl;
        // cout << one[0][i].y << " " << zero[1][i].y << " " << (one[0][i].y + zero[1][i].y) << " " << (1 << i) << " " << ((one[0][i].y + zero[1][i].y) & (1 << i)) << endl;
        // cout << zero[0][i].y << " " << one[1][i].y << " " << (zero[0][i].y + one[1][i].y) << " " << (1 << i) << " " << ((zero[0][i].y + one[1][i].y) & (1 << i)) << endl;
        if ((one[0][i].y && zero[1][i].y)) {
            // cout << "!" << endl;
            ll t = (one[0][i].y + zero[1][i].y) & (1LL << i);
            if (!t) continue;
        }

        // cout << "10 test" << endl;
        if ((zero[0][i].y && one[1][i].y)) {
            // cout << "!!" << endl;
            if (!((zero[0][i].y + one[1][i].y) & (1LL << i))) continue;
        }

        // 1... 1...
        // cout << "11 test" << endl;
        // cout << one[0][i].x << " " << one[1][i].x << " " << (one[0][i].x + one[1][i].x) << " " << (1 << i) << " " << ((one[0][i].x + one[1][i].x) & (1 << i)) << endl;
        if (one[0][i].x != test && one[1][i].x != test) {
            if (!((one[0][i].x + one[1][i].x) & (1LL << i))) continue;
        }

        // cout << "PASS"  << " " << (1 << i ) << endl;
        ans += (1LL << i);
    }
    cout << ans << endl;
    return 0;
}