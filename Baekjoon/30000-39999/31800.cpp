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
    vector<int> v(N), vv(N);
    for (auto &i : v) cin >> i;
    for (auto &i : vv) cin >> i;

    vector<int> vw = v;
    sort(all(vw));
    for (int i = 0; i < N; i++) {
        if (vw.back() == v[i]) {
            cout << v[i] - (vw[N-2] - vv[i]) - vv[i] << " ";
        } else {
            cout << v[i] - (vw[N-1] - vv[i]) - vv[i] << " ";
        }
    }
    cout << endl;
    return 0;
}