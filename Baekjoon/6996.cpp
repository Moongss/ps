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
    
    int T; cin >> T;
    while (T--) {
        string a, b; cin >> a >> b;
        string ta, tb; ta = a, tb = b;
        sort(all(a)); sort(all(b));


        cout << ta << " & " << tb << " are " << (a == b ? "anagrams." : "NOT anagrams.") << endl;

    }
    return 0;
}