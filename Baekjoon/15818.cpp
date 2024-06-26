#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    ll N, M; cin >> N >> M;

    ll result = 1;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        result = ((result % M) * (a % M)) % M;
    }
    cout << result << endl;
    return 0;
}