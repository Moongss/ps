#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, K, X;
int prevNode[20];
int flow[20][20];
int cost[20][20];
int score[16];
vector<int> adj[20];
vector<int> result[20];

void addEdge(int s, int e, int cst) {
    adj[s].push_back(e);
    adj[e].push_back(s);
    
    cost[s][e] = cst;
}

void solve(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto &nxt : adj[cur]) {
            if (prevNode[nxt] != -1) continue;
            if (cost[cur][nxt] - flow[cur][nxt] <= 0) continue;
            
            prevNode[nxt] = cur;
            q.push(nxt);
            if (nxt == e) return;
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> K >> X;
    for (int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int target; cin >> target;
            addEdge(i, target + N, 1);
        }
    }

    for (int i = 1; i <= N; i++) { //정렬해야됨
        cin >> score[i];
    }

    int s = 0, e = 19;
    for (int i = 1; i <= N; i++)
        addEdge(s, i, 0x3f3f3f3f);
    for (int i = 1; i <= K; i++) {
        addEdge(N + i, e, X);
    }

    while (true) {
        solve(s, e);
        if (prevNode[e] == -1) break;

        for (int i = e; i != s; i = prevNode[i]) {
            if ((1 <= prevNode[i] && prevNode[i] <=  N) && 
                (N + 1 <= i && i <= N + K))
                result[i - N].push_back(prevNode[i]);
                
            flow[prevNode[i]][i]++;
            flow[i][prevNode[i]]--;
        }
    }

    for (int i = 1; i <= K; i++) {
        cout << result[i].size() << " ";
        for (auto x : result[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}