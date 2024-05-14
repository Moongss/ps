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

    ll N, M; cin >> N >> M;

    ll sum = 0;
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        sum += x;
        if (sum < 0) sum = 0;
        if (sum >= M) cnt++;
    }
    cout << cnt << endl;
    return 0;
}