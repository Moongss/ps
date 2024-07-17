#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define coord first
#define dist second
const ll inf = (1LL << 63) - 1;

set<int> s;
queue<pii> q;
int main() {
    fastio;
    
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        s.insert(x);
        q.push({x - 1, 1});
        q.push({x + 1, 1});
    }

    ll ret = 0;
    while (!q.empty() && K) {
        auto &elem = q.front(); q.pop();

        if (s.find(elem.coord) == s.end()) {
            s.insert(elem.coord);
            K--; ret += elem.dist;
            q.push({elem.coord - 1, elem.dist + 1});
            q.push({elem.coord + 1, elem.dist + 1});
        }
    }

    cout << ret << endl;
    return 0;
}