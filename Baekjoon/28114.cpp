#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> v;
vector<pair<int, string>> vs;

int main() {
    fastio;
    
    for (int i = 0; i < 3; i++) {
        int p, y; string name; cin >> p >> y >> name;
        v.push_back(y);
        vs.push_back({p, name});
    }

    sort(v.begin(), v.end());
    sort(vs.begin(), vs.end(), greater<>());
    for (int i = 0; i < 3; i++) {
        cout << v[i] % 100;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << vs[i].second[0];
    }
    cout << endl;
    return 0;
}