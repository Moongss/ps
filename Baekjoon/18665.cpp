#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

ll N;
set<ll> s;

void solve(ll N) {
    ll x = 1; while (x * x < N) x++;
    ll y = (x * x == N) ? 0 : x * x - N;
    if (s.find(N) == s.end()) {
        if (s.find(x) == s.end()) {
            solve(x);
            s.insert(x);
        }
        if (s.find(y) == s.end()) {
            solve(y);
            s.insert(y);
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    fastio;
    cin >> N;

    s.insert(0);
    s.insert(1);
    s.insert(2);

    solve(N);
    return 0;
}