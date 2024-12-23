#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;


int dp[1000][1000];
vector<pii> v;
int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    dp[0][0] = v[0].x;
    dp[0][1] = v[0].y;
    for (int i = 1; i < v.size(); i++){
        dp[i][0] = max(dp[i - 1][0] + abs(v[i].y - v[i - 1].y) + v[i].x,
                       dp[i - 1][1] + abs(v[i].y - v[i - 1].x) + v[i].x);
        dp[i][1] = max(dp[i - 1][0] + abs(v[i].x - v[i - 1].y) + v[i].y,
                       dp[i - 1][1] + abs(v[i].x - v[i - 1].x) + v[i].y);
    }
    cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
    return 0;
}