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
    
    int N, M; cin >> N >> M;
    int min1, min6;

    min1 = min6 = 4242;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        min6 = min(min6, x);
        min1 = min(min1, y);
    }

    int ret = min6 * (N / 6) + min1 * (N % 6);
    ret = min(ret, min6 * ((N / 6) + 1));
    ret = min(ret, min1 * N);
    cout << ret << endl;
    return 0;
}