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
vector<ll> pre;
int main() {
    fastio;
    
    for (int i = 3; i <= 80000; i++) {
        if (i % 3 == 0 || i % 7 == 0) v.push_back(i);
    }
    pre.resize(sz(v)); pre[0] = v[0];
    for (int i = 1; i < sz(v); i++) pre[i] = pre[i - 1] + v[i];

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << pre[upper(v, N) - 1] << endl;
    }
    return 0;
}