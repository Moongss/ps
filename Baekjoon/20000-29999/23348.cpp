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
    
    int A, B, C;
    cin >> A >> B >> C;
    int N;
    cin >> N;

    int res = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            int a, b, c; cin >> a >> b >> c;
            sum += a * A + b * B + c * C;
        }
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
}