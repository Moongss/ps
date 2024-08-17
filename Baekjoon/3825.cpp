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

bool sum[20001];
void sieve() {
    for (int i = 0; i * i <= 20000; i++) {
        for (int j = 0; j * j <= 20000; j++) {
            int a = i * i + j * j;
            if (a > 20000) continue;
            sum[a] = true;
        }
    }
}

int main() {
    fastio;
    
    sieve();
    int T; cin >> T;
    while (T--) {
        int m, n; cin >> m >> n;
        int a = m * m + n * n;

        bool f = false;
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0 && sum[a/i] && sum[i]) {
                f = true;
                break;
            }
        }
        cout << (f ? "C" : "P") << endl;
    }
    return 0;
}