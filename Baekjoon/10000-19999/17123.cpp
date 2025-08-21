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

int t; 
int n, m;
int arr[1010][1010];
int rowpre[1010], colpre[1010];
int main() {
    fastio;
    
    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(rowpre, 0, sizeof(rowpre));
        memset(colpre, 0, sizeof(colpre));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
                rowpre[i] += arr[i][j];
                colpre[j] += arr[i][j];
            }
        }

        while (m--) {
            int r1, c1, r2, c2, k; cin >> r1 >> c1 >> r2 >> c2 >> k;
            for (int i = r1; i <= r2; i++) {
                rowpre[i] += k * (c2 - c1 + 1);
            }
            for (int i = c1; i <= c2; i++) {
                colpre[i] += k * (r2 - r1 + 1);
            }
        }

        for (int i = 1; i <= n; i++) cout << rowpre[i] << " "; cout << endl;
        for (int i = 1; i <= n; i++) cout << colpre[i] << " "; cout << endl;
    }

    
    return 0;
}