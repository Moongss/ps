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
    ld R; cin >> R;
    printf("%.6Lf\n", R * R * M_PI);
    printf("%.6Lf\n", R * R * 2);
    return 0;
}