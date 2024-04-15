#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool check[100001];
int main() {
    fastio;
    
    int N; cin >> N;

    int eMin = 100000, sMax = 0;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        eMin = min(eMin, e);
        sMax = max(sMax, s);
    }

    cout << max(0, sMax - eMin) << endl;
    return 0;
}