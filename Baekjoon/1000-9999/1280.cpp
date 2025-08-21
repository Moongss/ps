#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1000000007;
const ll SZ = 1 << 20;
ll visited[SZ << 1];
ll dist[SZ << 1];

void SetVisit(int x, ll v) {
    x += SZ; visited[x] = v;
    while (x /= 2) visited[x] = visited[x*2] + visited[x*2+1];
}

void SetDist(int x, ll v) {
    x += SZ; dist[x] = v;
    while (x /= 2) dist[x] = dist[x*2] + dist[x*2+1];
}

ll SumVisit(int l, int r) {
    ll res = 0;
    for (l+=SZ, r+=SZ; l <= r; l/=2, r/=2) {
        if (l % 2 == 1) res += visited[l++];
        if (r % 2 == 0) res += visited[r--];
    }
    return res;
}

ll SumDist(int l, int r) {
    ll res = 0;
    for (l+=SZ, r+=SZ; l <= r; l/=2, r/=2) {
        if (l % 2 == 1) res += dist[l++];
        if (r % 2 == 0) res += dist[r--];
    }
    return res;
}

int main() {
    fastio;
    int N; cin >> N;
    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        ll curDist = 0;
        if (i > 1) {
            curDist += (SumVisit(0, x - 1) * x - SumDist(0, x - 1)) % MOD;
            curDist += (SumDist(x + 1, SZ) - SumVisit(x + 1, SZ) * x) % MOD;
            ans = ((ans % MOD) * (curDist % MOD)) % MOD;
        }
        SetVisit(x, visited[x + SZ] + 1);
        SetDist(x, dist[x + SZ] + x);
    }
    cout << ans << endl;
    return 0;
}