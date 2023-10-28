#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            char ch; cin >> ch;
            if (ch == 'w') {
                cout << "chunbae" << endl;
                return 0;
            } else if (ch == 'b') {
                cout << "nabi" << endl;
                return 0;
            } else if (ch == 'g') {
                cout << "yeongcheol" << endl;
                return 0;
            }
        }
    }
    return 0;
}