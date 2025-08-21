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
    ll result = 0;

    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        result ^= (a - 2);
    }

    string start; cin >> start;
    if (start == "Whiteking") {
        cout << (result ? "Whiteking" : "Blackking") << endl;
    }
    else {
        cout << (result ? "Blackking" : "Whiteking") << endl;
    }
    return 0;
}