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
    int M, D; cin >> M >> D;
    if (M < 2) {
        cout << "Before" << endl;
    } else if (M == 2) {
        if (D < 18) {
            cout << "Before" << endl;
        } else if (D == 18) {
            cout << "Special" << endl;
        } else {
            cout << "After" << endl;
        }
    } else {
        cout << "After" << endl;
    }
    return 0;
}