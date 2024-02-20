#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int prevNode[202];
int capacity[202][202];
int flow[202][202];
bool isDie[202];
vector<int> adj[202];
vector<tuple<int, int, int>> v;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) >= get<0>(b) && 
        get<1>(a) >= get<1>(b) &&
        get<2>(a) >= get<2>(b))
        return true;
    return false;
}

void setFlow(int s, int e, int flow) {
    capacity[s][e] = flow;

    adj[s].push_back(e);
    adj[e].push_back(s);
}

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto nxt : adj[cur]) {
            if (prevNode[nxt] != -1) continue;
            if (capacity[cur][nxt] - flow[cur][nxt] <= 0) continue;

            q.push(nxt);
            prevNode[nxt] = cur;
            if (nxt == e) return;
        }
    }
}

int main() {
    fastio;
    
    cin >> N; v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i] = {a, b, c};
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (v[i] == v[j] && i < j) setFlow(i, j + 50, 1);
            if (v[i] != v[j] && compare(v[i], v[j])) setFlow(i, j + 50, 1);
        }
    }

    int s = 0;
    int e = 123;
    for (int i = 1; i <= N; i++) {
        setFlow(s, i, 2);
    }
    for (int i = 1; i <= N; i++) {
        setFlow(i + 50, e, 1);
    }

    int totalShark = 0;
    while (true) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        for (int i = e; i != s; i = prevNode[i]) {
            flow[prevNode[i]][i]++;
            flow[i][prevNode[i]]--;
        }
        totalShark++;
    }
    cout << N - totalShark << endl;
    return 0;
}