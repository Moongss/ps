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
    int N, M; cin >> N >> M;
    ll result = 0;

    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < M; j++) {
            ll tmp; cin >> tmp;
            sum += tmp;
        }
        result ^= sum;
    }

    cout << (result ? "august14" : "ainta") << endl;
    return 0;
}