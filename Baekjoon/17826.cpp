#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    vector<int> v(50);
    for (int i = 0; i < 50; i++) {
        cin >> v[i];
    }
    sort(all(v)); reverse(all(v));

    int t; cin >> t;
    int ans;
    for (int i = 0; i < 50; i++) {
        if (v[i] == t) {
            ans = i+1; break;
        }
    }

    if (ans <= 5) cout << "A+" << endl;
    else if (ans <= 15) cout << "A0" << endl;
    else if (ans <= 30)cout << "B+" << endl;
    else if (ans <= 35)cout << "B0" << endl;
    else if (ans <= 45)cout << "C+" << endl;
    else if (ans <= 48)cout << "C0" << endl;
    else if (ans <= 50)cout << "F" << endl;
    return 0;
}