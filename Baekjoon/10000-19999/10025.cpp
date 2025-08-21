#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, K;
ll arr[1000002];
ll pre[1000002];

int main() {
    fastio;
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        arr[y] = x;
    }

    for (int i = 1; i <= 1000000; i++) {
        pre[i] = arr[i - 1] + pre[i - 1];
    }


    ll res = -1;
    for (int i = 0; i <= 1000000; i++) {
        int r = min(1000000, i + K);
        int l = max(0, i - K - 1); 

        // cout << "l : " << max(0, i - K - 1) << ", r : " << min(1000000, i + K) << endl;
        res = max(res, pre[r] - pre[l]);
    }
    cout << res << endl;
    return 0;
}