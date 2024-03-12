#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll N, sum;

int main() {
    fastio;
    
    cin >> N;
    ll sum = N * (N - 1) / 2;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; sum -= x;
    }
    cout << abs(sum) << endl;
    return 0;
}