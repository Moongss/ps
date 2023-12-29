#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N; cin >> N;
    vector<ll> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    ll cnt = 1;
    for (int i = 0; i < N - 1; i++) {
        if (v[i] <= v[i + 1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}