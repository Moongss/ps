#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll arr[1000001];

int main() {
    fastio;
    
    int n; cin >> n;
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        arr[i] = (arr[i - 1]% 1000000007 + arr[i - 2]% 1000000007) % 1000000007;
    }

    cout << arr[n] % 1000000007 << endl;
    return 0;
}