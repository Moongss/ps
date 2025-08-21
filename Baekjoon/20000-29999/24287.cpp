#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll N, K;
ll arr[5050][5050];
ll pre[5050][5050];

int main() {
    fastio;
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    int lo = 0, hi = N + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        bool f = true;
        for (int i = N; i >= mid && f; i--) {
            for (int j = N; j >= mid && f; j--) {
                int sum = pre[i][j] - pre[i-mid][j] - pre[i][j-mid] + pre[i-mid][j-mid];
                if (sum < K) {
                    f = false;
                    break;
                }
            }
        }

        if (f) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    if (hi == N + 1) hi = -1;
    cout << hi << endl;
    return 0;
}