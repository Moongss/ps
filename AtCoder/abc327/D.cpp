#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M;
int nodeGroup[200001];
vector<int> graph[200001];
int A[200001];
int B[200001];
bool flag = true;

void dfs(int v, int groupId) {
    nodeGroup[v] = groupId;
    for (int i = 0; i < graph[v].size(); i++) {
        int cur = graph[v][i];
        if (nodeGroup[cur] == -1) dfs(cur, (groupId + 1) % 2);
        if (nodeGroup[cur] == groupId) {
            flag = false;
            return;
        }
    }    
    return;
}
int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i <= 200000; i++) { nodeGroup[i] = -1; }
    for (int i = 0; i < M; i++) { cin >> A[i]; }
    for (int i = 0; i < M; i++) { cin >> B[i]; }

    for (int i = 0; i < M; i++) {
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (nodeGroup[i] == -1) dfs(i, 0);
        if (!flag) break;
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}