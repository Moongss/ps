#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int V, E;
int visited[10001];
int visitCnt = 0;

vector<int> isAnswer;
vector<int> adj[10001];

int dfs(int cur, bool isRoot) {
    visited[cur] = ++visitCnt;
    int child = 0;
    int minNode = visited[cur];
    for (int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (!visited[next]) {
            child++;
            int tmp = dfs(next, false);
            if (!isRoot && tmp >= visited[cur]) { // or tmp >= visited[cur];
                isAnswer.push_back(cur);
            }
            minNode = min(minNode, tmp);
        } else {
            minNode = min(minNode, visited[next]);
        }
    }
    if (isRoot && child >= 2) {
        isAnswer.push_back(cur);
    }
    return minNode;
}

int main() {
    fastio;
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 1; i <= V; i++) {
        if (!visited[i])
            dfs(i, true);
    }

    sort(isAnswer.begin(), isAnswer.end());
    isAnswer.erase(unique(isAnswer.begin(), isAnswer.end()), isAnswer.end());

    cout << isAnswer.size() << endl;
    for (auto &node : isAnswer) {
        cout << node << " ";
    }
    return 0;
}