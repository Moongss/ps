#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int result = 0;
int arr[3][3] = {
    {0, 1, 2},
    {1, 2, 0},
    {2, 0, 1}
};

int main() {
    fastio;
    
    cin >> N;
    ll result = 0;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        result ^= (((x / 3) ^ (y / 3)) * 3 + arr[x % 3][y % 3]);
    }

    cout << (result ? "koosaga" : "cubelover") << endl;
    return 0;
}