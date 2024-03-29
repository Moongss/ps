#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T, N;
int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 1) cout << 0 << endl;
        else if (N == 2) cout << "11" << endl;
        else if (N == 3) cout << "121" << endl;
        else {
            cout << "11";
            for (int i = 0; i < N - 4; i++) {
                cout << "0";
            }
            cout << "11" << endl;
        }
    }
    return 0;
}