#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ull = unsigned long long; 
using ll = long long;
using ld = long double;

int main() {
    fastio;
    ull n; cin >> n;

    ull lo = 0;
    ull hi = 4e+9;
    while (lo + 1 < hi) {
        ull mid = (lo + hi) / 2;
        if (mid * mid >= n) hi = mid;
        else lo = mid;
    }
    
    cout << (n == 0 ? 0 : hi) << endl;
    return 0;
}