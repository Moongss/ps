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
    
    string s; cin >> s;
    if (s[0] == '0') cout << 0 << endl;
    else {
        int cnt = 0;
        for (int i = 1; i < (s.length()+1) / 2; i++) {
            if (s[i] != '0') cnt++;
        }
        if (s.length() % 2 == 0) {
            string a = s.substr(0, s.length()/2);
            string b = s.substr(s.length()/2, s.length()/2);
            if (b[0] != '0') {
                if (a <= b) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}