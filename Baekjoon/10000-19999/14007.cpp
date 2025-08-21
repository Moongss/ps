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
    vector<int> v; v.resize(N); for (auto &i : v) cin >> i;

    int ret = N;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            int prev = v[i];
            bool f = (v[i] < v[i+1]);
            bool f2 = true;
            for (int k = i+1; k <= j; k++) {
                int cur = v[k];
                if (f && prev < cur || !f && prev > cur) {
                    f = !f;
                    prev = cur;
                } else {
                    f2 = false;
                    break;
                }
            }
            if (f2) {
                ret++;
            }
        }
    }
    cout << ret << endl;
    return 0;
}