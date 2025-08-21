#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int result = 0;
vector<int> v;

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        result ^= p;
        v.push_back(p);
    }

    if (result == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        result ^= v[i];
        for (int j = 1; j <= v[i]; j++) {
            result ^= (v[i] - j);
            if (result == 0) cnt++;
            result ^= (v[i] - j);
        }
        result ^= v[i];
    }
    cout << cnt << endl;
    return 0;
}