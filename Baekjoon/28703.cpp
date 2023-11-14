#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

priority_queue<ll> pq;
vector<ll> v;
int main() {
    fastio;
    int N; cin >> N;
    ll maxA = -1;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        pq.push(-x);
        maxA = max(maxA, x);
    }

    ll ans = 4242424242;
    ll tmp = maxA;
    while (-pq.top() <= maxA) {
        ll elem = -pq.top(); pq.pop();
        ans = min(ans, tmp - elem);
        tmp = max(tmp, elem * 2);
        pq.push(-elem * 2);
    }
    cout << ans << endl;
    return 0;
}