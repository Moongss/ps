#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int s = 0;
        for (int i = 0; i < N; i++) {
            s++;
            int x; cin >> x;
            if (s == x) s++;
        }
        cout << s << endl;
    }
    return 0;
}