#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        string K; cin >> K;
        cout << (((K.back() - '0') % 2) ? "odd" : "even") << endl;
    }

    return 0;
}