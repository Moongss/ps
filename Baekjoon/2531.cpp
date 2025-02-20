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

int N, d, k, c;
vector<int> v;
int cnt[3030];

int main() {
    fastio;

    cin >> N >> d >> k >> c;
    for (int i = 0; i < N + k; i++) {
        if (i < N) {
            int a; cin >> a;
            v.push_back(a);
        } else {
            v.push_back(v[i-N]);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (!cnt[v[i]]) ans++;
        cnt[v[i]]++;
    }

    int tmp = ans;
    int lo = 0, hi = k-1;
    while (lo < N) {
        cnt[v[lo]]--;
        if (!cnt[v[lo]]) tmp--;
        lo++;
        hi++;
        if (!cnt[v[hi]]) tmp++;
        cnt[v[hi]]++;

        if (!cnt[c]) ans = max(ans, tmp+1);
        else ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}