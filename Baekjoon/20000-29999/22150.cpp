#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        bool f = true;
        for (int i = 0; i < N; i++) {
            int l, r; cin >> l >> r;
            if (l + r != N) f = false;
        }
        cout << (f ? "no" : "yes") << endl;
    }
    return 0;
}