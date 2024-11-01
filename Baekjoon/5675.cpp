#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    // fastio;
    
    set<int> s;
    int n;

    // for (int i = 0; i <= 60*12; i++) {
    //     int a = (i / 12) * 6;
    //     int b = (i % 60) * 6;

    //     if (i % 12 == 0) {
    //         if (abs(a-b) > 180) s.insert(abs(a-b) - 180);
    //         else s.insert(abs(a-b));
    //     }
    // }
    while (cin >> n) {
        if (n % 6) cout << "N" << endl;
        else cout << "Y" << endl;
        // if (s.find(n) != s.end()) cout << "Y" << endl;
        // else cout << "N" << endl;
    }
    return 0;
}