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
    
    int N; cin >> N;
    string s; cin >> s; reverse(all(s));

    int ret = 0;
    for (int i = 0; i < N-1; i++) {
        if (!ret && s[i] == '1') ret++;
        else if (ret && s[i] == '0') ret++;
    }
    cout << ret << endl;
    return 0;
}