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

int N;
int dp[300001];
vector<int> v;

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1, cur = 0, prv = 0; ;i++) {
        cur += i; if (cur + prv > N) break;
        v.push_back(cur + prv);
        prv += cur;
    }

    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    for (auto &x : v) {
        for (int i = x; i <= N; i++) {
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }

    cout << dp[N] << endl;
    return 0;
}