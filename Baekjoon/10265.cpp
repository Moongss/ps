#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, K;

int cnt = 0;
int parent[1001];
bool finished[1001];

vector<int> sccNum;
vector<int> adj[1001]; //?
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
        int sccCnt = 0;
        while (true) {
            int elem = tmp.top(); tmp.pop();
            finished[elem] = true;
            sccCnt++;
            if (elem == cur) break;
        }
        sccNum.push_back(sccCnt);
    }

    return ret;
}

int main() {
    // fastio;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        adj[i].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
        if (!parent[i])
            scc(i);
    }

    sort(sccNum.begin(), sccNum.end(), greater<>());
    int result = 0;
    for (auto e : sccNum) {
        cout << "e : "<< e << endl;
        if (K >= e) {
            cout << "k - e :" << e << endl;
            K -= e;
            result += e;
        }
    }

    cout << result << endl;
    return 0;
}