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
    
    string s, e;
    cin >> s >> e;
    cout << (s.size() >= e.size() ? "go" : "no") << endl;
    return 0;
}