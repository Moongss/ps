#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> v;

ll getEulerPhi(ll X) {
    ll ret = X;
    for (ll i = 2; i * i <= X; i++) {
        if (X % i) continue;
        else {
            ret /= i;
            ret *= (i - 1);
            while (!(X % i)) X /= i;
        }
    }
    if (X > 1) {
        ret /= X;
        ret *= (X - 1);
    }
    return ret;
}

int main() {
    fastio;
    ll N; cin >> N;

    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            v.push_back(i);
            v.push_back(N / i);
        }
    }
    sort(v.begin(), v.end());

    for (auto p : v) {
        if (getEulerPhi(p) == N / p) {
            cout << p << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}