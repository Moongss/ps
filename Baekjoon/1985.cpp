#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

string x, y;

int main() {
    fastio;
    
    cin >> x >> y;
    for (auto c : x) {
        for (auto d : y) {
            if (c == d) continue;
        }
    }
    return 0;
}