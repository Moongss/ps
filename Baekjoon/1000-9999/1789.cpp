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
    
    ll N; cin >> N;
    ll sum = 0;
    ll i = 1;
    for (;;i++) {
        sum += i;
        if (sum > N) break;
    }
    cout << i - 1 << endl;
    return 0;
}