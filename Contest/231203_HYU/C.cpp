#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M, K;
vector<int> adj[200001];
int discovered[200001];
bool isCutVertex[200001];

int cutCnt = 0;
bool flag = false;
bool checkIsCycle(int cur, int prev) {
    for (int next : adj[cur]) {
        if (isCutVertex[next]) continue;
        if (next == prev) continue;

        // cout << "cur : " << cur << " next : " << next << endl;
        if (discovered[next] == -1) {
            discovered[next] = discovered[cur] + 1;
            checkIsCycle(next, cur);
        }
        else if (discovered[cur] > discovered[next]) {
            // cout << "DISCOVER cur : " << cur << " next : " << next << endl;
            flag = true;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    queue<pair<int, int>> q; 
    for (int i = 1; i <= K; i++) {
        int node; cin >> node;
        q.push({node, 0});
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int curTime = q.front().second;
        q.pop();

        if (isCutVertex[cur]) continue;  

        memset(discovered, -1, sizeof(discovered)); 
        discovered[cur] = 0;
        flag = false;
        checkIsCycle(cur, -1);
        if (!flag) {
            // cout << "cur : " << cur << " curTime : " << curTime << endl;
            if (curTime == 0)
                cout << 1 << endl;
            else
                cout << curTime << endl;
            return 0;
        }
        isCutVertex[cur] = true;
        for (int next : adj[cur]) {
            if (isCutVertex[next]) continue;
            q.push({next, curTime + 1});
        }
    }
    cout << -1 << endl;
    return 0;
}