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
    
    int N, P; cin >> N >> P;

    int Max = P;
    if (N >= 20) Max = min(max(0, (int)(P * 0.75)), Max);
    if (N >= 15) Max = min(max(0, P - 2000), Max);
    if (N >= 10) Max = min(max(0, (int)(P * 0.9)), Max);
    if (N >= 5) Max = min(max(0, P - 500), Max);

    cout << Max << endl;
    return 0;
}