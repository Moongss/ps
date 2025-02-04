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

    int Max = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        Max += abs(x);
    }
    int Min = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        Min -= abs(x);
    }
    cout << Max - Min << endl;
    return 0;
}