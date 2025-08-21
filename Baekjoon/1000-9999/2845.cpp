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
    int L, P; cin >> L >> P;
    for (int i = 0; i < 5; i++) {
        int tmp; cin >> tmp; 
        cout << tmp - L * P << " ";
    }
    return 0;
}