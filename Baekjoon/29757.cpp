#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using piii = pair<pair<int, int>, int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
vector<piii> v;
int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        v.push_back({{x, y}, i});
    }

    sort(v.begin(), v.end());
    for (int i = 1; i < N; i++) {
        cout << v[i - 1].second << " " << v[i].second << endl;
    }
    return 0;
}