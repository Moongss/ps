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

int main() {
    fastio;
    
    map<int, int> m;
    int sum = 0;
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < 10; i++) {
        int x; cin >> x; sum += x;
        m[x]++;
        if (m[x] > cnt) {
            cnt = m[x];
            ret = x;
        }
    }
    cout << sum / 10 << endl;
    cout << ret << endl;
    return 0;
}