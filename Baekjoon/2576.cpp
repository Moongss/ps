#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int sum = 0;
    int Min = 101;
    for (int i = 0; i < 7; i++) {
        int x; cin >> x;
        if (x % 2) sum += x;
        if (x % 2) Min = min(Min, x);
    }
    if (sum == 0) cout << -1 << endl;
    else cout << sum << endl << Min << endl;
    return 0;
}