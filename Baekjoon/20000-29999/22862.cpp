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

int N, K;
vector<int> v;
int main() {
    fastio;
    
    cin >> N >> K;
    v.resize(N); for (auto &i : v) cin >> i;

    int l = 0, r = 0, ans = 0, cnt = 0;
    while (l <= r && r < N) {
        if (v[r] % 2 != 0) cnt++;
        if (cnt > K) {
            if (v[l] % 2 != 0) cnt--;
            l++;
        } else {
            ans = max(ans, r - l + 1 - cnt);
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}