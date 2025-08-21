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

int N;
vector<int> v;
set<tuple<int, int, int>> s;

void in(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    s.insert({a, b, c});
}

int main() {
    fastio;
    
    cin >> N;
    v.resize(N);
    for (auto &i: v) cin >> i;
    sort(all(v));

    ll ans = 0;
    for (int i = 2; i < N; i++) {
        int lo = 0;
        int hi = i - 1;

        while (lo < hi) {
            int sum = v[lo] + v[hi] + v[i];

            if (sum == 0) {
                in(lo, hi, i);
                while (lo + 1 < hi && v[lo] == v[lo + 1]) {
                    lo++;
                    in(lo, hi, i);
                }
                while (lo + 1 < hi && v[hi] == v[hi - 1]) {
                    hi--;
                    in(lo, hi, i);
                }
            }

            if (sum < 0) {
                lo = (lo + 1 == i) ? lo + 2 : lo + 1;
            } else {
                hi = (hi - 1 == i) ? hi - 2 : hi - 1;
            }
        }
    }

    cout << s.size() << endl;
    return 0;
}