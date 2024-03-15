#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, D; 
int cnt[303030];

int main() {
    fastio;
    cin >> N >> D;

    int s = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; cnt[x]++;
        s = max(s, x);
    }

    ll sum = 0;
    while (D--) {
        if (s == 0) break;
        sum += cnt[s];
        cnt[s - 1] += cnt[s];
        s--;
    }

    cout << sum << endl;
    return 0;
}