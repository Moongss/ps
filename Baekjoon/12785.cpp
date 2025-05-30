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

int w, h; 
int x, y; 
ll arr[202][202];
int mod = 1000007;
int main() {
    fastio;
    
    cin >> w >> h;
    cin >> x >> y;

    arr[1][0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % mod;
        }
    }

    cout << (arr[y][x]% mod * arr[h-y+1][w-x+1]% mod) % mod << endl;
    return 0;
}