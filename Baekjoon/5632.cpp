#include <bits/stdc++.h>
#include <ext/rope>
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
using namespace __gnu_cxx;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int T, vnow;
ll cnt;
rope<char> r[50001];
int getC(string s) {
    int cnt = 0;
    for (auto &c : s) if (c == 'c') cnt++;
    return cnt;
}

int main() {
    fastio;
    
    cin >> T;
    vnow = 1;
    while (T--) {
        int q; cin >> q;
        if (q == 1) {
            ll p; string s; cin >> p >> s; p -= cnt; 
            r[vnow].insert(p, s.c_str());
            r[vnow + 1] = r[vnow];
            // cout << "vnow : " << vnow << " " << r[vnow] << endl;
            // cout << "vnow + 1 : " << vnow + 1 << " " << r[vnow] << endl;
            vnow++;
        }
        if (q == 2) {
            ll p, q; cin >> p >> q; p -= cnt, q -= cnt; p--;
            r[vnow].erase(p, q);
            r[vnow + 1] = r[vnow];
            // cout << "vnow : " << vnow << " " << r[vnow] << endl;
            // cout << "vnow + 1 : " << vnow + 1 << " " << r[vnow] << endl;
            vnow++;
        }
        if (q == 3) {
            ll v, p, c; cin >> v >> p >> c; v -= cnt, p -= cnt; c -= cnt; p--;
            // cout << "vnow : " << v << " " << r[v] << endl;
            string s = r[v].substr(p, c).c_str();
            cnt += getC(s);
            // cout << "cnt : " << cnt << endl;
            cout << s << endl;
        }
    }
    return 0;
}