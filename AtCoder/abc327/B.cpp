#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    ll B;
    cin >> B;

    for (ll i = 1; i <= 17; i++) {
        ll sum = 1;
        for (ll j = 1; j <= i; j++) {
            sum *= i;
        }
        if (sum == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}