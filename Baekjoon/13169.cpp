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
#define sz(v) (int)v.size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
vector<ll> v;
vector<ll> A, B;

vector<ll> bitA[36], bitB[36];
bitset<36> bs;

int main() {
    fastio;
    
    cin >> N;
    v.resize(N); for (auto &i : v) cin >> i;

    if (N == 1) cout << v[0] << endl;
    else {
        int mid = N / 2;
        for (int i = 0; i < (1 << mid); i++) {
            ll sum = 0;
            for (int j = 0; j < mid; j++) {
                if (i & (1 << j)) sum += v[j];
            }
            A.push_back(sum);
        }

        for (int i = 0; i < 36; i++) {
            for (auto &x : A) {
                bitA[i].push_back(x & ((1LL << (i + 1)) - 1));
            }
        }

        for (int i = 0; i < (1 << (N - mid)); i++) {
            ll sum = 0;
            for (int j = 0; j < N - mid; j++) {
                if (i & (1 << j)) sum += v[mid + j];
            }
            B.push_back(sum);
        }

        for (int i = 0; i < 36; i++) {
            for (auto &x : B) {
                bitB[i].push_back(x & ((1LL << (i + 1)) - 1));
            }
        }

        // ....0101
        // ....1011
        // ...10000
        // 맞냐?
        // 두 비트를 더했을때 carry가 발생하지 않으려면...
        // 이렇게하면 안됨

        // 두 수의 합 X + Y을 xor한 결과를 이분탐색으로 진행.
        // 각 비트별로 밀고 올라간다. 어떻게?

        // 00001111 마스킹해서 몇개인지 세야함. (1 << (bit + 1)) - 1
        
        // 4번째 bit가 1이 되려면?
        // x + y = (1 << bit) 1000
        // x + y ~ (1 << (bit + 1)) 10000 미만.
        // (1 << (bit)) - x
        // (1 << (bit + 1)) - x;
        // 이거면 되나?
        for (int i = 0; i < 36; i++) {
            ll ret = 0;
            sort(all(bitB[i]));
            for (auto &x : bitA[i]) {
                // cout << "bitA[i] : " << x << endl;
                // cout << "(1 << (i + 1)) - x : " << (1 << (i + 1)) - x << endl;
                // cout << "(1 << i) - x : " << (1 << i) - x << endl;
                // cout << "upper : " << upper(bitB[i], (1 << (i + 1)) - x + 1) << endl;
                // cout << "lower : " << lower(bitB[i], (1 << i) - x) << endl;
                ret += upper(bitB[i], (1LL << (i + 1)) - x + 1) - lower(bitB[i], (1LL << i) - x);
            }
            // cout << "ret : " << ret << endl;
            if (ret % 2) bs[i] = 1;
        }
        cout << bs.to_ullong() << endl;
    }
    return 0;
}