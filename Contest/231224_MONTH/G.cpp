#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

deque<ll> A;
int main() {
    fastio;
    
    ll N, M; cin >> N >> M;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        A.push_back(a);
        sum += a;
    }

    while (!A.empty() && M > 0) {
        M %= sum;
        if (M >= A.front()) {
            M -= A.front();
            A.push_back(A.front());
        } else {
            sum -= A.front();
        }
        A.pop_front();
    }
    cout << M << endl;
    return 0;
}