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
    for (int i = 1; i <= N; i*=10) {
        result += N - i + 1;
    }
    cout << result << endl;
    return 0;
}