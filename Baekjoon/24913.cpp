#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, Q;
ll arr[101010];

int main() {
    fastio;
    
    cin >> N >> Q;

    ll sum = 0;
    pll mmax = {-1, 42};
    while (Q--) {
        int q; cin >> q;
        if (q == 1) {
            int x, p; cin >> x >> p;
            arr[p] += x;
            if (p != N + 1) sum += x;
            if (mmax.x < arr[p] && p != N + 1) mmax = {arr[p], p};
        } else {
            int x, y; cin >> x >> y;

            // cout << "arr[N + 1] + x : " << arr[N + 1] + x << ", mmax.x : " << mmax.x << endl;
            // cout << "(arr[N + 1] + x - 1) * N : " << (arr[N + 1] + x - 1) * N 
            //     << ", sum + y : " << sum + y << endl;
            if (arr[N + 1] + x > mmax.x && (arr[N + 1] + x - 1) * N >= sum + y) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}