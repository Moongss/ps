#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":" << endl;

        string str; cin >> str;
        bool f = false;
        for (int i = str.length() - 1; i > 0 && !f; i--) {
            for (int j = str.length() - 1 - i; j >= 0; j--) {
                string tmp = str.substr(j, i + 1);
                reverse(tmp.begin(), tmp.end());
                if (tmp == str.substr(j, i + 1)) {
                    cout << tmp << endl;
                    f = true;
                }
            }
        }

    }
    return 0;
}