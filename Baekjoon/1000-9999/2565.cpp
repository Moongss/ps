#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
vector<pair<int, int> >v;
vector<int> result;

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    for (auto elem : v) {
        int cur = elem.second;
        if (result.empty()) result.push_back(cur);
        else {
            int pos = lower_bound(result.begin(), result.end(), cur) - result.begin();
            if (pos < result.size())
                result[pos] = cur;
            else
                result.push_back(cur);
        }
    }
    cout << N - result.size() << endl;
    return 0;
}