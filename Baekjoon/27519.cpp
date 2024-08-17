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

bool prime[100001];
vector<int> primes;
ll dp[100001];

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 100000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 100000; i++) {
        if (prime[i]) primes.push_back(i);
    }
}

int main() {
    fastio;
    
    sieve();
    int T; cin >> T;
    
    dp[0] = 1;
    for (auto &p : primes) {
        for (int i = p; i <= 100000; i++) {
            if (i - p < 0) break;
            dp[i] += dp[i - p];
            dp[i] %= 1000000007;
        }
    }
    // for (int i = 2; i <= 10; i++) {
    //     for (auto &p : primes) {
    //         if (i - p < 0) break;
    //         dp[i] += dp[i - p];
    //         dp[i] %= 1000000007;
    //     }
    //     // if (prime[i]) dp[i]++;
    //     dp[i] %= 1000000007;
    // }

    while (T--) {
        ll x; cin >> x;
        cout << dp[x] % 1000000007<< endl;
    }
    return 0;
}