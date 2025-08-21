#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, M;
vector<int> adj[100001];
int color[100001];

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        adj[y].push_back(x);
    }

    fill(color, color + N + 1, 1);
    for (int i = 1; i <= N; i++) {
        set<int> grundy;
        for (auto &j : adj[i]) {
            grundy.insert(color[j]);
        }

        int g = 1;
        while (grundy.count(g)) g++;
        color[i] = g;
    }

    for (int i = 1; i <= N; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
    return 0;
}