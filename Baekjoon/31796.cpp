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
    int N; cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int sum = 1;
    int cur = v[0];
    for (int i = 1; i < N; i++) {
        if (v[i] < cur * 2) continue;

        cur = v[i];
        sum++;
    }
    cout << sum << endl;
    return 0;
}