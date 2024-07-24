#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        ll N; cin >> N; cout << N * (N - 1) / 2 << endl;
    }
    return 0;
}