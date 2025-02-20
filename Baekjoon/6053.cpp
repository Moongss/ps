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
    
    int N;
    vector<int> v1, v2;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; v.push_back(x);
    }

    v1.resize(N);
    v2.resize(N);
    v1[0] = 1;
    for (int i = 1; i < N; i++) {
        if (v[i] >= v[i-1]) v1[i] = v1[i-1]+1;
        else v1[i] = 1;
    }

    v2[N-1] = 1;
    for (int i = N-2; i >= 0; i--) {
        if (v[i] >= v[i+1]) v2[i] = v2[i+1]+1;
        else v2[i] = 1;
    }


    ll ans = 0;
    for (int i = 0; i < N; i++ ){
        ans = max(ans, (ll)v1[i] + v2[i] - 1);
    }
    cout << ans << endl;
    return 0;
}