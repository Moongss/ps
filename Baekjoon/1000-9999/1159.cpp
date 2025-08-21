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

char v[26];
int main() {
    fastio;
    
    int N; cin >> N;
    bool f = false;
    while (N--) {
        string str; cin >> str; v[str[0] - 'a']++;
        if (v[str[0] - 'a'] >= 5) f = true;
    }

    if (!f) cout << "PREDAJA" << endl;
    else {
        for (int i = 0; i < 26; i++) {
            if (v[i] >= 5) cout << (char)('a' + i);
        }
        cout << endl;
    }
    return 0;
}