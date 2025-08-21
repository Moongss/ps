#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int K, N;
int scc[10001];
int sccIdx = 0;

int parent[10001];
int parentIdx = 0;
bool finished[10001];
stack<int> s;
vector<int> adj[10001];

int SCC(int cur) {
    s.push(cur);
    int ret = parent[cur] = ++parentIdx;
    for (auto nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, SCC(nxt));
        else if (!finished[nxt]) ret = min(ret, parent[nxt]);
    }
    if (ret == parent[cur]) {
        while (1) {
            int t = s.top(); s.pop();
            scc[t] = sccIdx;
            finished[t] = true;
            if (t == cur) break;
        }
        ++sccIdx;
    }
    return ret;
}

int main() {
    fastio;
    cin >> K >> N;
    while (N--) {
        int l1, l2, l3;
        char c1, c2, c3;
        cin >> l1 >> c1 >> l2 >> c2 >> l3 >> c3;

        if (c1 == 'B') l1 *= -1;
        if (c2 == 'B') l2 *= -1;
        if (c3 == 'B') l3 *= -1;

        l1 = (abs(l1) - 1) * 2 + (l1 < 0);
        l2 = (abs(l2) - 1) * 2 + (l2 < 0);
        l3 = (abs(l3) - 1) * 2 + (l3 < 0);

        adj[l1 ^ 1].push_back(l2);
        adj[l2 ^ 1].push_back(l1);

        adj[l2 ^ 1].push_back(l3);
        adj[l3 ^ 1].push_back(l2);

        adj[l3 ^ 1].push_back(l1);
        adj[l1 ^ 1].push_back(l3);
    }

    for (int i = 0; i < 2 * K; i++) 
        if (!parent[i]) 
            SCC(i);

    for (int i = 0; i < 2 * K; i+=2) {
        if (scc[i] == scc[i + 1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    //coloring lamp with scc topology-sort 
    //scc가 가능하므로 그냥 위상정렬 순서로 정하면 된다. 
    //또는 평소 하던대로 sccGroup, nodeNum에 따라 색칠하면 될듯..
    //0 : R, 1 : B
    for (int i = 0; i < 2 * K; i+=2) {
        if (scc[i] > scc[i + 1]) // 근데 먼저 나오는걸 false로 정하기. 
            cout << "B";
        else
            cout << "R";
    }
    cout << endl;


    return 0;
}