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

int N;
int cnt[4];
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    int k = min(cnt[0], cnt[3]);
    ans += 3 * k; cnt[0] -= k; cnt[3] -= k;

    k = min(cnt[1], cnt[2]);
    ans += 3 * k; cnt[1] -= k; cnt[2] -= k;

    k = min(cnt[1], cnt[3]);
    ans += 2 * k; cnt[1] -= k; cnt[3] -= k;

    k = min(cnt[0], cnt[2]);
    ans += 2 * k; cnt[0] -= k; cnt[2] -= k;

    k = min(cnt[1], cnt[0]);
    ans += k; cnt[1] -= k; cnt[0] -= k;

    k = min(cnt[2], cnt[3]);
    ans += k; cnt[2] -= k; cnt[3] -= k;

    cout << ans << endl;
    
    return 0;
}