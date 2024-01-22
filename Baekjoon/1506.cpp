#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;

int cnt = 0;
int parent[100];
int cost[100];
bool finished[100];

int result = 0;
vector<int> adj[100];
stack<int> tmp;

int scc(int cur) {
    parent[cur] = ++cnt;
    int ret = parent[cur];

    tmp.push(cur);
    for (auto nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, scc(nxt));
        if (!finished[nxt]) ret = min(ret, parent[nxt]);
    }

    if (ret == parent[cur]) {
        int minCost = INT_MAX;
        while (true) {
            int elem = tmp.top(); tmp.pop();
            minCost = min(minCost, cost[elem]);
            finished[elem] = true;
            if (elem == cur) break;
        }
        result += minCost;
    }
    return ret;
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        cost[i] = x;
    }

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1')
                adj[i].push_back(j);
        }
    }

    for (int i = 0; i < N; i++) {
        if (!parent[i]) 
            scc(i);
    }

    cout << result << endl;
    return 0;
}