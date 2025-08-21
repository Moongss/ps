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
    
    string str; cin >> str;
    set<string> s;

    for (int i = 1; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            string sub1 = str.substr(0, i);
            string sub2 = str.substr(i, j - i);
            string sub3 = str.substr(j, str.length() - j);

            reverse(all(sub1));
            reverse(all(sub2));
            reverse(all(sub3));
            s.insert(sub1 + sub2 + sub3);
        }
    }
    cout << *s.begin() << endl;
    return 0;
}