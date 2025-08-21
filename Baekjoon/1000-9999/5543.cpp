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
    
    vector<int> a(3), b(2);
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1];

    int res = 42424242;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            res = min(res, a[i] + b[j]);
        }
    }
    cout << res - 50<< endl;
    return 0;
}