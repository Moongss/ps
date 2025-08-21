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
    int a, b, c, d; cin >> a >> b >> c >> d;

    int total = a * 3600 + b * 60 + c + d;
    while (total >= 86400) total -= 86400;

    cout << (total / 3600) << " " << (total % 3600) / 60 << " " << ((total % 3600) % 60) << endl;
    return 0;
}