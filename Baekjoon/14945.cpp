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

int arr[101][101];
int main() {
    fastio;
    
    int N; cin >> N;
    arr[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1] + 2 * arr[i - 1][j];
            arr[i][j] %= 10007;
        }
    }

    ll ans = 0; 
    for (int i = 2; i <= N; i++) {
        ans += arr[N][i];
    }
    cout << (ans * 2) % 10007 << endl;


    return 0;
}