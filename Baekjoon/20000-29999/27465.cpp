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
    int N; cin >> N;
    if (N <= 2) {
        cout << 42 << endl;
    } else {
        if (N % 2 == 0) cout << N << endl;
        else cout << N + 1 << endl;
    }
    return 0;
}