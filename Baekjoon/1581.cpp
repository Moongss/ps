#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    int ff, fs, sf, ss;
    cin >> ff >> fs >> sf >> ss;

    int ret = 0;
    if (ff == 0 && fs == 0) {
        cout << ss + (sf ? 1 : 0) << endl;
    } else if (ff != 0 && fs == 0) {
        cout << ff << endl;
    } else {
        int ret = (fs ? 1 : 0) + ss;
        fs--;
        bool f = false;
        while (true) {
            if (!f) {
                if (!sf) break;
                ret++; sf--;
                f = true;
            } else {
                if (!fs) break;
                ret++; fs--;
                f = false;
            }
        }
        cout << ret + ff << endl;
    }
    return 0;
}