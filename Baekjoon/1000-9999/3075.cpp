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

ll sum[101]; 
ll arr[101][101];
vector<int> v;
bool check[101];

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        for (int i = 1; i <= 100; i++) 
        for (int j = 1; j <= 100; j++) 
        {arr[i][j] = 0x3f3f3f3f; if (i == j) arr[i][j] = 0;}
        
        memset(sum, 0, sizeof(sum));

        int n, p, q; cin >> n >> p >> q;
        vector<int> v; v.resize(n); for (auto &i : v) cin >> i;
        while (q--) {
            int i, j, d; cin >> i >> j >> d;
            if (d < arr[i][j]) arr[i][j] = d;
            if (d < arr[j][i]) arr[j][i] = d;
        }

        for (int k = 1; k <= p; k++) {
            for (int i = 1; i <= p; i++) {
                for (int j = 1; j <= p; j++) {
                    if (arr[i][k] >= 0x3f3f3f3f) continue;
                    if (arr[k][j] >= 0x3f3f3f3f) continue;
                    if (arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }

        memset(check, true, sizeof(check));
        for (int i : v) {
            for (int j = 1; j <= p; j++) {
                if (arr[i][j] >= 0x3f3f3f3f) {check[j] = false; continue;}
                sum[j] += arr[i][j] * arr[i][j];
            }
        }

        pair<ll, int> ret = {0x3f3f3f3f3f, 42};
        for (int i = 1; i <= p; i++) {
            if (ret.x > sum[i] && check[i]) ret = {sum[i], i};
        }
        cout << ret.y << " " << ret.x << endl;
    }
    return 0;
}