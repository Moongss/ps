#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    int N, Q; cin >> N >> Q;
    int cnt[101010]; int arr[101010];
    memset(cnt, 0, sizeof(cnt));
    memset(arr, 0, sizeof(arr));
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    while (Q--) {
        int q,k; cin >> q >> k;
        if (q == 1) {
            if (N == 1) {
                cout << 0 << endl;
                continue;
            }
            bool f = false;
            for (int i = 1; i*i <= k; i++) {
                if (k % i == 0) {
                    if (k/i == i && cnt[i] > 1) f = true;
                    else if (k/i != i && k/i <= 10000 && i <= 10000 && cnt[i] > 0 && cnt[k/i] > 0) f = true;
                }
            }
            if (k == 0 && cnt[0]) f = true;
            cout << f << endl;
        } else {
            cnt[arr[k]] = max(0, cnt[arr[k]] - 1);
            arr[k] = 0;
            cnt[0]++;
        }
    }
    return 0;
}