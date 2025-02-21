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

int main() {
    fastio;

    ll N; cin >> N;
    ll sum = 0;

    ll tmp = 10;
    ll prv = 1;

    for (int i = 1; i <= 10; i++) {
        if (N < tmp) {
            sum += ((N - prv + 1) * (i));
            cout << sum % 1234567 << endl;
            return 0;
        }
        sum += ((tmp - prv) * (i));
        prv = tmp;
        tmp *= 10;
    }

    return 0;
}