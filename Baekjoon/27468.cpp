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
    int n; cin >> n;

    int pos[4] = {1, 2, 4, 3};
    int pos2[4] = {1, 3, 2, 4};
    int k = n / 4 * 4;
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if ((n-1) % 4 == 2) {
            cout << i/4*4 + pos2[i%4] << " ";
        } else {
            cout << i/4*4 + pos[i%4] << " ";
        }
    }
}