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
    int cnt = 0;
    for (int i = 0; i <= 6; i++) {
        if ((1 << i) & N) cnt++;
    }
    cout << cnt << endl;
    return 0;
}