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
    
    int E, S, M;
    cin >> E >> S >> M;

    ll cnt = 0;
    int i = 0, j = 0, k = 0;
    while (true) {
        i = i % 15 + 1;
        j = j % 28 + 1;
        k = k % 19 + 1;
        cnt++;
        if (i == E && j == S && k == M) {
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}