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
int dp[500001];
bool sieve[1000001];

vector<int> v;
void getSieve() {
    memset(sieve, true, sizeof(sieve));
    for (int i = 2; i <= 1000000; i++) {
        if (!sieve[i]) continue;
        for (int j = i + i; j <= 1000000; j += i)
            sieve[j] = false;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) v.push_back(i);
    }
}

int main() {
    fastio;
    
    cin >> N;
    getSieve();

    vector<int> ret;
    ret.push_back(2);
    ret.push_back(2 + N % 2);
    for (int i = 2; i <= N - 4 - N % 2; i++) {
        if (sieve[i] && sieve[N - 4 - N % 2 - i ]) {
            ret.push_back(i);
            ret.push_back(N - 4 - N % 2 - i);
            break;
        }
    }
    if (ret.size() == 4) {
        sort(all(ret)); for (auto &e : ret) cout << e << " ";
    } 
    else cout << -1 << endl;
    return 0;
}