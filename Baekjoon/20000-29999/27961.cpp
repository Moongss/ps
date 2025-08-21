#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    ll N; cin >> N;
    ll cnt = 1;

    if (N == 0) {cout << 0 << endl; return 0;}
    while (((ll)1 << (cnt - 1)) < N) {
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}