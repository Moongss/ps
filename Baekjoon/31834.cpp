#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, s, e;
        cin >> n >> s >> e;
        
        // if (s > e) swap(s, e);
        // if (s == 1 && e == n) cout << 0 << "\n";

        if (s == 1 && e == n || s == n && e == 1) cout << 0 << "\n";
        else if (s == 1 || s == n || abs(s - e) == 1) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    
    return 0;
}