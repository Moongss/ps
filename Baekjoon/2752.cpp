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
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    return 0;
}