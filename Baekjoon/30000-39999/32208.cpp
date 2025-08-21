#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int main() {
    fastio;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        if (x & 1) cout << ((y & 1) ^ (z & 1) ? "YES" : "NO") << endl;
        else cout << (!((y & 1) ^ (z & 1)) ? "YES" : "NO") << endl;
    }
    return 0;
}