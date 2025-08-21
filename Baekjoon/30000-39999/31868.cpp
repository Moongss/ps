#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

ll N, K;
int main() {
    fastio;
    
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        K /= 2;
    }
    cout << K << endl;
    return 0;
}