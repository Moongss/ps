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
    
    int N; cin >> N;
    int cnt = 0;

    int Max; cin >> Max;
    int ret = 0;
    for (int i = 1; i<N; i++) {
        int x; cin >> x;
        if (x > Max) {
            cnt = 0;
            Max = x;
        } else {
            cnt++;
        }
        ret = max(ret, cnt);
    }
    cout << ret << endl;
    return 0;
}