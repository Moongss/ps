#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int T; ll N;
int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        cin >> N;
        
        ll sum1 = 0;
        ll divisor = 2;
        while (N > divisor) {
            sum1 += (N / divisor);
            divisor *= 2;
        }

        ll sum2 = 0;
        divisor = 5;
        while (N > divisor) {
            sum2 += (N / divisor);
            divisor *= 5;
        }

        cout << min(sum1, sum2) << endl;
    }

    return 0;
}