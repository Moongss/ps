#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> v;

int main() {
    fastio;
    int N, M; cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}