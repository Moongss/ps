#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct Edge {
    int u, v, capacity, flow;
    Edge *prev;

    Edge(int a, int b, int c) :u(a), v(b), capacity(c), flow(0) {}; 
    void setFlow(int f) {
        flow += f;
        prev->flow -= f;
    }
};

int N, M;
int s, e;
char board[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

Edge *prevEdge[20001];
vector<Edge *> adj[20001];

void addEdge(int u, int v, int cap) {
    Edge *cur = new Edge(u, v, cap);
    Edge *prev = new Edge(v, u, 0);

    cur->prev = prev;
    prev->prev = cur;
    adj[u].push_back(cur);
    adj[v].push_back(prev);
}

void dfs() {
    memset(prevEdge, 0, sizeof(prevEdge));
    
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (Edge *edge : adj[cur]) {
            int nxt = edge->v;
            if (prevEdge[nxt]) continue;
            if (edge->capacity - edge->flow <= 0) continue;

            q.push(nxt);
            prevEdge[nxt] = edge;
            if (nxt == e) return;            
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    // cout << "s : " << s << ", e : " << e << endl;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ++cnt;
            if (board[i][j] == '#') continue;
            else {
                //set in/out node
                if (board[i][j] == 'K') s = cnt * 2;
                if (board[i][j] == 'H') e = cnt * 2 - 1;

                int inNode = cnt * 2 - 1;
                int outNode = cnt * 2;
                // cout << "u : " << inNode << ", v : " << outNode << endl;
                addEdge(inNode, outNode, 1);

                //set adj node
                for (int t = 0; t < 4; t++) {
                    int newX = i + dx[t];
                    int newY = j + dy[t];
                    if (newX < 1 || newX > N || newY < 1 || newY > M) continue;
                    if (board[newX][newY] == '#') continue;

                    int newNodeNum = ((newX - 1) * M + newY) * 2 - 1;
                    // cout << "u : " << outNode << ", nxt : " << newNodeNum << endl;
                    addEdge(outNode, newNodeNum, 1);
                }
            }
        }
    }

    int total = 0;
    while (1) {
        dfs();
        if (!prevEdge[e]) break;
        if (prevEdge[e]->u == s) {
            cout << -1 << endl;
            return 0;
        }

        for (int i = e; i != s; i = prevEdge[i]->u) {
            prevEdge[i]->setFlow(1);
        }
        total++;
    }
    cout << total << endl;
    return 0;
}