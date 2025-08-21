#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    string j; cin >> j;
    int N; cin >> N;
    int cnt = 0;

    while (N--) {
        string t; cin >> t;
        if (j == t) cnt++;
    }
    cout << cnt << endl;
    return 0;
}