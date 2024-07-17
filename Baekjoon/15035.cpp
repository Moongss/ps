#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    int N; cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int H; cin >> H;
    int mod = 424242; int res;
    for (auto &x : v) {
        if ((H % x) < mod) {mod = H % x; res = x;}
    }
    cout << res << endl;
    return 0;
}