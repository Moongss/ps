#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
bool adj[201][201];

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        adj[a][b] = adj[b][a] = true;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {
                if (adj[i][j] || adj[j][k] || adj[k][i]) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}