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

int N, K; double S;
ld ret = 0;

int main() {
    fastio;

    cin >> N >> S >> K;
    
    pair<int, double> pre = {1, S};
    while (K--) {
        int M; cin >> M >> S; 
        ret += (M - pre.x) * 4 / (pre.y / 60);
        pre = {M, S};
    }
    ret += (N- pre.x+1) * 4 / (pre.y/60);
    cout << fixed << setprecision(12) << ret << endl;
    return 0;
}