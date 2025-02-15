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

struct Cpon {
    int stay, pay, repeat;

    Cpon(int stay, int pay, int repeat) : stay(stay), pay(pay), repeat(repeat) {}
};

int main() {
    fastio;

    while (true) {
        string s; getline(cin, s);
        if (s == "#") break;

        vector<Cpon> v; 
        while (true) {
            int a, b, c; cin >> a >> b >> c;
            if (a + b + c == 0) break;
            v.push_back({a, b, c});
        }

        while (true) {
            int q; cin >> q;
            if (q == 0) break;

            int ans = q;
            for (auto &c : v) {
                for (int r = 1; r <= c.repeat; r++ ){
                    int sleep = r * c.stay;
                    if (sleep > q) break;

                    int rr = q - sleep;
                    ans = min(ans, rr + r * c.pay);
                }
            }
            string tt = (q == 1) ? "night" : "nights";
            cout << "Stay " << q << " " << tt << " at " << s << ", pay " << ans << "." << endl;
        }
        cin.ignore();
    }
    return 0;
}