#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

ll N;
set<ll> s;
void solve(ll x, ll y) {
    if (x <= 1 && y <= 1) {
        cout << x << " " << y << endl;
        return;
    }
    if (s.find(x) == s.end()) {
        ll i = 1;
        while (i * i < x) i++;

        if (i * i == x)
            solve(i, 0);
        else
            solve(i, i * i - x);
        s.insert(x);
    }
    if (s.find(y) == s.end()) {
        ll i = 1;
        while (i * i < y) i++;

        if (i * i == y)
            solve(i, 0);
        else
            solve(i, i * i - y);
        s.insert(y);
    }
    cout << x << " " << y << endl;
}

int main() {
    fastio;
    cin >> N;

    s.insert(0);
    s.insert(1);
    s.insert(2);

    ll i = 1;
    while (i * i < N) i++;
    if (i * i == N)
        solve(i, 0);
    else
        solve(i, i * i - N);
    return 0;
}