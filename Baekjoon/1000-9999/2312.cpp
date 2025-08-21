#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve(int N) {
    map<int, int> m;
    for (int i = 2;i < N;i++) {
        while (N % i == 0) {
            m[i]++;
            N /= i;
        }
    }
    if (N > 1) m[N]++;
    for (auto &x : m) {
        cout << x.first << " " << x.second << endl;
    }
}
int main() {
    fastio;
    int N; cin >> N;

    while (N--) {
        int t; cin >> t;
        solve(t);
    }
    return 0;
}