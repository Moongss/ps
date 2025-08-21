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

int t[] = {4, 6, 4, 10};
map<string, int> m;
int main() {
    fastio;
    
    int N; cin >> N;
    while (N--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {
                string str; cin >> str;
                if (str == "-") continue;
                else {
                    m[str] += t[i];
                }
            }
        }
    }
    
    int mmin = 42424242;
    int mmax = -1;
    for (auto &i : m) {
        mmin = min(mmin, i.second);
        mmax = max(mmax, i.second);
    }
    cout << (abs(mmin - mmax) <= 12? "Yes" : "No") << endl;
    return 0;
}