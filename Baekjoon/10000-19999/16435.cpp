#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> v;

int main() {
    fastio;

    cin >> N >> M; 
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    for (auto x : v) {
        if (M >= x) M++;
        else break;
    }
    
    cout << M << endl;
    return 0;
}