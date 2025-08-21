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
bool grouped[11];

int ans = 42424242;

bool check(int cnt) {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!grouped[i]) {
            q.push(i);
            visited[i] = true;
            break;
        }
    }

    int tmp = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (!visited[nxt] && !grouped[nxt]) {
                visited[nxt] = true;
                tmp++;
                q.push(nxt);
            }
        }
    }

    return (N - cnt == tmp);
}

void bfs(int start, int cnt) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int tmp = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (!visited[nxt] && grouped[nxt] == grouped[cur]) {
                visited[nxt] = true;
                tmp++;
                q.push(nxt);
            }
        }
    }
    
    if (cnt == tmp && check(cnt)) {
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= N; i++) {
            if (grouped[i]) sum1 += population[i];
            else sum2 += population[i];
        }
        ans = min(ans, abs(sum1 - sum2));
    }
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
    }

    for (int i = 1; i <= N; i++) {
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
            groupSum.push_back(population[i]);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (auto nxt : adj[cur]) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        groupSum[groupIdx] += population[nxt]; 
                        q.push(nxt);
                    }
                }
            }
        }
    }

    if (groupIdx >= 2) {
        ans = -1;
    } else if (groupIdx == 1) {
        ans = abs(groupSum[0] - groupSum[1]);
    } else {
        for (int i = 1; i < (1 << N); i++) {
            int cnt = 0;
            int start = 0;
            memset(grouped, false, sizeof(grouped));
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    start = j + 1;
                    grouped[j + 1] = true;
                    cnt++;
                }
            }
            bfs(start, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}