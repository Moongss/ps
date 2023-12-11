#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
priority_queue<int, vector<int>, greater<>> pq;
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    ll ans = 0;
    if (N != 1) {
        while (pq.size() > 2) {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        while (!pq.empty()) {
            ans += pq.top(); pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}