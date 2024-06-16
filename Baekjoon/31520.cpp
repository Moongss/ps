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
    
    string N;
    cin >> N;

    int idx = 1;
    for (int i = 0; i < N.length(); i++) {
        if (idx != N[i] - '0') {
            cout << -1 << endl;
            return 0;
        }
        idx++;
    }
    cout << idx - 1 << endl;

    return 0;
}