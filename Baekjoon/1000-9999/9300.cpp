#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        ld h, angle; 
        cin >> h >> angle;

        angle = tan(angle * M_PI / 180.0f);
        if (angle == 0.0f) printf("Case %d: Infinity\n", i + 1);
        else printf("Case %d: %.6Lf\n", i + 1, fabs((h / angle) - h));
    }
    return 0;
}
