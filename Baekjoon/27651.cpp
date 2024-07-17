#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

ll N;
ll pre[1000001];

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }   

    ll cnt = 0;
    for (int i = 1; i <= N - 2; i++) {
        ll lo = i + 1, hi = N;
        ll maxY = lo;
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;

            if (pre[i] < pre[N] - pre[mid]) {
                lo = mid;
                maxY = mid;
            } else {
                hi = mid;
            }
        }
        
        lo = i; hi = N - 1;
        ll minY = hi;
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;

            if (pre[N] - pre[mid] < pre[mid] - pre[i]) {
                hi = mid;
                minY = mid;
            } else {
                lo = mid;
            }
        }

        if (pre[i] < pre[N] - pre[maxY] &&
            pre[N] - pre[minY] < pre[minY] - pre[i] &&
            minY <= maxY) {
            cnt += maxY - minY + 1;
        }
    }
    cout << cnt << endl;
    return 0;
}