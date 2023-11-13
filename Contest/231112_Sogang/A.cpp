#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int t; cin >> t;
    ll happy = 0;
    int prevL = 0;
    int prevR = 0;
    while (t--) {
        int l, r; cin >> l >> r;
        if (l == r && l != 0) happy++;
        if (l == prevL && l != 0) happy++;
        if (r == prevR && r != 0) happy++;
        prevL = l; prevR = r;
    }
    cout << happy << endl;
    return 0;
}