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

string s;
ll ret = 0;

void solve(int cur, ll save, int jcnt, int mcnt, bool check) {
    // cout << "cur : " << cur << ", s[cur] : "<< s[cur] << ", save : " << save << ", cnt : "<< jcnt << ", " << mcnt << ", check :  "<< check << endl;
    if (jcnt == 3 || mcnt == 3) return;
    if (cur >= s.length()) {
        if (check && jcnt < 3 && mcnt < 3)  {
            ret += save;
            // cout << "save : " << save << endl;
        }
        return;
    }

    if (s[cur] >= 'A' && s[cur] <= 'Z') {
        if (s[cur] == 'A' || s[cur] == 'E' || s[cur] == 'I' || s[cur] == 'O' || s[cur] == 'U') {
            solve(cur + 1, save, 0, mcnt + 1, check);
        } else if (s[cur] == 'L') {
            solve(cur + 1, save, jcnt + 1, 0, true);
        } else {
            solve(cur + 1, save, jcnt + 1, 0, check);
        }
    } else {
        if (jcnt < 2) {
            solve(cur + 1, save, jcnt + 1, 0, true);
            solve(cur + 1, save * (26 - 5 - 1), jcnt + 1, 0, check);
        }
        if (mcnt < 2) {
            solve(cur + 1, save * 5, 0, mcnt + 1, check);
        }
    }
}
int main() {
    fastio;
    
    cin >> s;
    solve(0, 1, 0, 0, false);
    cout << ret << endl;
    return 0;
}