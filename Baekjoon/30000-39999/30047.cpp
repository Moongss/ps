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
    
    stack<int> save;
    string s; cin >> s;
    reverse(all(s));

    for (auto &c : s) {
        if (c == 'x') {
            save.push(0);
        }
        if (c == 'g') {
            if (save.size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            int cur = save.top(); save.pop();
            save.push(cur + 1);
        }
        if (c == 'f') {
            if (save.size() <= 1) {
                cout << -1 << endl;
                return 0;
            }
            int p = save.top(); save.pop();
            int c = save.top(); save.pop();
            save.push(min(p, c));
        }
    }

    if (save.size() != 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << save.top() << endl;
    return 0;
}