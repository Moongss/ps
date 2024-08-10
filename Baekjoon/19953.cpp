#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

ll v, m, t;
int x, y;
int dv[4];

int main() {
    fastio;
    
    cin >> v >> m >> t;

    x = 0, y = v;
    for (int i = 1; i <= 4; i++) {
        v = (v * m) % 10;
        dv[i % 4] = v;
    }

    x += ((t - 1) / 4) * (dv[1] - dv[3]) + ((t - 1) % 4 >= 1) * dv[1] - ((t - 1) % 4 >= 3) * dv[3];
    y += ((t - 1) / 4) * (dv[0] - dv[2]) - ((t - 1) % 4 >= 2) * dv[2];
    cout << x << " " << y << endl;
    return 0;
}