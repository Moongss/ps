#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N; cin >> N;
    if (N == 3) cout << -1 << endl;
    else if (N % 2) {
        cout << N-2 << endl;
        for (int i = 1; i < N-2; i++) cout << i << endl;
        cout << N << endl << N-1 << endl;
    }
    else {
        for (int i = 2; i >= 1; i--) cout << i << endl;
        for (int i = N; i > 2; i--) cout << i << endl;
    }
    return 0;
}