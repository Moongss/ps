#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    int N, B; cin >> N >> B;
    int ret = 1;

    for (int i = N; i >= 1; i--) {
        int tmp = i;

        // 아래 코드 최적화
        while (tmp % B == 0) {
            tmp /= B;
        }

        ret *= tmp;
        ret %= B;
    }
    cout << ret << endl;
    return 0;
}