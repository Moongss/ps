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

    string max = "", min = "";
    int cnt = 0;
    for (auto &c : str) {
        if (c == 'K') {
            if (cnt) {
                max += '5'; min += '1';
                for (int i = 0; i < cnt; i++) max += '0';
                for (int i = 1; i < cnt; i++) min += '0';
                min += '5';
            } else {
                max += '5'; min += '5';
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }

    if (cnt) {
        max += '1'; min += '1';
        for (int i = 1; i < cnt; i++) max += '1';
        for (int i = 1; i < cnt; i++) min += '0';
    }

    cout << max << endl << min << endl;
    return 0;
}