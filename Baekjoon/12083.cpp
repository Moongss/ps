#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int T, N;
int cnt, tmp;
map<string, int> m;
int color[202];
vector<int> adj[202];

void bfs(int cur) {
    color[cur] = 1;

    queue<int> q; q.push(cur);
    while (!q.empty()) {
        int elem = q.front(); q.pop();

        int nxtColor = (color[elem] == 1 ? 2 : 1);
        for (auto &x : adj[elem]) {
            if (!color[x]) {
                color[x] = nxtColor;
                q.push(x);
            }
        }
    }
}

bool test() {
    for (int i = 1; i <= cnt; i++) {
        for (auto &x : adj[i]) {
            if (color[i] == color[x]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        cin >> N;

        tmp++;
        cnt = 0;
        memset(color, 0, sizeof(color));
        memset(adj, 0, sizeof(adj));
        m.clear();

        for (int i = 0; i < N; i++) {
            string x, y; cin >> x >> y;
            if (m.find(x) == m.end()) m[x] = ++cnt;
            if (m.find(y) == m.end()) m[y] = ++cnt;

            adj[m[x]].push_back(m[y]);
            adj[m[y]].push_back(m[x]);
        }

        for (int i = 1; i <= cnt; i++) {
            if (color[i] == 0) {
                bfs(i);
            }
        }

        if (test()) {
            cout << "Case #" << tmp << ": Yes" << endl;
        } else {
            cout << "Case #" << tmp << ": No" << endl;
        }
    }
    return 0;
}