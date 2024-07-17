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

    int t; cin >> t;
    while (t--) {
        int evenMin = 42424242; int evenSum = 0;
        for (int i = 0; i < 7; i++) {
            int x; cin >> x;
            if (x % 2 == 0) {
                evenSum += x;
                evenMin = min(evenMin, x);
            }
        }
        cout << evenSum << " " << evenMin << endl;
    }   

    return 0;
}