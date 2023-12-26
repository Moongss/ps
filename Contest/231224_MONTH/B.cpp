#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> v(40000);
map<int, int> m;

int main() {
    fastio;
    int N;

    cin >> N;
    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            v[i + j]++;
        }
    }
    
    ll ans = (N * 2 + 1) * (N * 2 + 1);
    for (int i = -N; i <= N; i++) {
        if (i == 0) continue;
        ans += v[1 - i + 2 * N];
    }
    cout << ans << endl;
    return 0;
}