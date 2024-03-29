#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
ll f[117];

int main() {
    fastio;
    
    f[1] = f[2] = f[3] = 1;
    for (int i = 4; i <= 116; i++) {
        f[i] = f[i - 1] + f[i - 3];
    }

    cin >> N;
    cout << f[N] << endl;
    return 0;
}