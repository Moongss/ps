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
    
    ll N, K;
    cin >> N >> K;

    ll first = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        if (i == 0) {first = x; continue;}
        else {
            if (first + i * K >= x) {
                sum += (first + i * K) - x;
            } else {
                sum += (x - (first + i * K)) * i;
                first = x - i * K;
            }
        }
    }
    cout << sum << endl;
    return 0;
}