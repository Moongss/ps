#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        int x, y; cin >> x >> y;
        cout << "You get " << x / y << " piece(s) and your dad gets " << x % y << " piece(s)." << endl;
    }
    return 0;
}