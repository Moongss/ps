#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> v;

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        auto iter = lower_bound(v.begin(), v.end(), num);
        if (iter == v.end()) v.push_back(num);
        else *iter = num;
    }
    cout << v.size() << endl;
    return 0;
}