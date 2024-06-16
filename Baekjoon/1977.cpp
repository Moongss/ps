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
    int N, M; cin >> N >> M;

    ll sum = 0;
    ll mins = 0;
    for (int i = 1; i * i <= 10000; i++) {
        if (N <= i * i && i * i <= M) {
            sum += i*i;
            if (!mins) mins = i*i;
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << mins << endl;
    }
    return 0;
}