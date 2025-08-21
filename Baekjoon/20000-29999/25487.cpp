#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        cout << min({a, b, c}) << endl;
    }
    return 0;
}