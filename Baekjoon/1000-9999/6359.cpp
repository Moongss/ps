#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool arr[101];

int main() {
    fastio;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j += i) {
            arr[j] = !arr[j];
        }
    }

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i]) res++;
        }
        cout << res << endl;
    }    
    return 0;
}