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


ll N, Q, W;
stack<pii> s[202020];
int arr[202020];
map<int, int> m[202020];

ll ret = 0;
int main() {
    fastio;
    
    cin >> N >> W;
    for (int i =0; i < N; i++) {
        int a, b; cin >> a >> b;
        m[a][b] = i+1;
    }

    for (int i = 1; i <= W; i++) {
        for (auto j : m[i]) {
            s[i].push(j); // {time, val}
        }
    }

    int Min = 42424242;
    for (int i = 1; i <= W; i++) {
        Min = min(Min, (int)s[i].size());
    }

    for (int i = 1; i <= W; i++) {
        while (s[i].size() > Min) {
            arr[s[i].top().y] = -1;
            s[i].pop();
        }
    }

    while (Min--) {
        vector<int> v;
        int MM = 0;
        for (int i = 1; i <= W; i++) {
            if (s[i].top().x > MM) MM = s[i].top().x;
            v.push_back(s[i].top().y);
            s[i].pop();
        }
        for (auto i : v) {
            arr[i] = MM;
        }
    }

    cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y;

        if (arr[y] == -1) cout << "Yes" << endl;
        else if (arr[y] <= x) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}