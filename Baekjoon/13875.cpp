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

bool sieve[1010101];
vector<int> v;

void getsieve() {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) continue;
        v.push_back(i);
        for (int j = i + i; j <= 1000000; j += i) sieve[j] = true;
    }
}

int main() {
    fastio;
    
    getsieve();
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        pii ret;
        bool f= false;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > n-v[i]) break;
            if (!sieve[n - v[i]]) {
                f = true;
                ret = {v[i], n - v[i]};
                break;
            }
        }
        if (f) cout << n << " = " << ret.x << " + " << ret.y << endl;
        else cout << "Goldbach's conjecture is wrong." << endl;
    }
    return 0;
}