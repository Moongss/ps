#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < 20000; i++) {
        cout << "? " << N << endl;
        cout << flush;

        char result;
        cin >> result;
        if (result == 'Y') {
            cout << "! " << N << endl;
            cout << flush;
            break;
        }
    }
    return 0;
}