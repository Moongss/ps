#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int a, b, c, d; cin >> a >> b >> c >> d;
    int e, f, g, h; cin >> e >> f >> g >> h;
    cout << max(a + b + c + d, e + f + g + h) << endl;
    return 0;
}