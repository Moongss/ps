#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;

    ll x, y;
    cin >> x >> y;

    cout << 2 << endl;
    if (x < y) {
        cout << x * (y - 1) << endl;
        cout << - (x - 1) * y << endl;
    } else {
        cout << (y - 1) * x << endl;
        cout << - y * (x - 1) << endl;
    }
    return 0;
}