#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<ll> v;
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll tmp; cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int s = 0, e = 0;
    int tmp = 0;
    int ans = 0;
    while (s <= e && e < N) {
        if (v[e] - v[s] <= 4) {
            ans = max(ans, e - s + 1);
            e++;
        } else {
            s++;
        }
    }
    cout << 5 - ans << endl;
    return 0;
}