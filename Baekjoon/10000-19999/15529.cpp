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
    vector<int> v; v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(all(v));

    int ret = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            string c = to_string(v[i]*v[j]);
            
            bool f = true;
            for (int k = 1; k < c.length(); k++) {
                if (c[k] != c[k-1]+1) f = false;
            }
            if (f) ret = max(ret, v[i]*v[j]);
        }
    }
    cout << ret << endl;
    return 0;
}