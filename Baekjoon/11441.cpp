#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int pre[100001];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    
    cin >> M;
    while (M--) {
        int s, e; cin >> s >> e;
        cout << pre[e] - pre[s - 1] << endl;
    }
    return 0;
}