#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll N;
vector<ll> T;

int main() {
    fastio;
    
    cin >> N;
    T.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> T[i];
    }
    
    sort(T.begin(), T.end());
    ll result = 0;
    if (N % 2 == 0) {
        for (ll i = 0; i < N / 2; i++) {
            result = max(result, T[i] + T[N - 1 - i]);
        }
    } else {
        result = T[N - 1];
        for (ll i = 0; i < N / 2; i++) {
            result = max(result, T[i] + T[N - 2 - i]);
        }
    }
    cout << result << endl;
    return 0;
}