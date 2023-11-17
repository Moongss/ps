#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
vector<int> adj[11];
int population[101];
bool visited[11];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
    }

    for (int i = 0; i < N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int area; cin >> area;
            adj[i].push_back(area);
        }
    }

    int groupIdx = -1;
    vector<int> groupSum;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            groupIdx++;
            groupSum.push_back(0);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                groupSum[groupIdx] += population[cur]; 
                for (auto nxt : adj[cur]) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
    }

    if (groupSum.size() > 2) {
        cout << -1 << endl;
    } else if (groupSum.size() == 2) {
        cout << abs(groupSum[0] - groupSum[1]) << endl;
    } else {
        
    }

    int ans = 42424242;
    
    return 0;
}