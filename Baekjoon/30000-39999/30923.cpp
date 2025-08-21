#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> h;

int main() {
    fastio;

    cin >> N;
    h.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += (2 + h[i] * 4);
        if (i >= 2)
            sum -= min(h[i], h[i - 1]) * 2;
    }

    cout << sum << endl;
    
    return 0;
}