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

set<string> s;
int main() {
    fastio;

    while (true) {
        string str; cin >> str;
        if (str == "XXXXXX") break;

        s.insert(str);
    }

    while (true) {
        string str; cin >> str;
        if (str == "XXXXXX") break;

        sort(str.begin(), str.end());
        bool flag = false;
        do {
            if (s.find(str) != s.end()) {
                cout << str << endl;
                flag = true;
            }
        } while (next_permutation(str.begin(), str.end()));

        if (!flag) cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
    
    return 0;
}