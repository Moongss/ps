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
    
    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        int tmp = N + 1;
        N %= 100;

        if (tmp % N == 0) cout << "Good\n";
        else cout << "Bye\n";
    }
    return 0;
}