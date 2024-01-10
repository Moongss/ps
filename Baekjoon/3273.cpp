#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N; cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int x; cin >> x;
    int result = 0;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(v.begin() + (i + 1), v.end(), x - v[i]) - v.begin();
        if (idx < N && v[i] + v[idx] == x)
            result++;
    }
    cout << result << endl;
    return 0;
}