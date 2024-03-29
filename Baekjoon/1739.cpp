#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T, N, M, K;
int parent[4040];
int sccId[4040];
int sccIdx = 0;
int cnt = 0;
vector<int> adj[4040];
stack<int> s;

void init() {
    cnt = 0;
    sccIdx = 0;
    memset(parent, 0, sizeof(parent));
    memset(sccId, 0, sizeof(sccId));
    for (int i = 0; i < 4040; i++) {
        adj[i].clear();
    }
    while (!s.empty()) {
        s.pop();
    }
}

int dfs(int cur) {
    parent[cur] = ++cnt;
    s.push(cur);

    int ret = parent[cur];
    for (auto nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, dfs(nxt));
        if (!sccId[nxt]) ret = min(ret, parent[nxt]);
    }

    if (ret == parent[cur]) {
        sccIdx++;
        while (true) {
            int elem = s.top(); s.pop();
            sccId[elem] = sccIdx;
            if (elem == cur) break;
        }
    }
    return ret;
}

int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        init();
        cin >> N >> M >> K;

        while (K--) {
            int A, B, C, D; cin >> A >> B >> C >> D;
            

            //x-axis: 1 ~ 2000
            int x_true[2] = {A * 2 - 1, C * 2 - 1};
            int x_false[2] = {A * 2, C * 2};

            //y-axis: 2001 ~ 4000
            int y_true[2] = {B * 2 - 1 + 2000, D * 2 - 1 + 2000};
            int y_false[2] = {B * 2 + 2000, D * 2 + 2000};

            if (A == C && B == D) continue;
            if (B > D) {
                swap(x_true[0], x_false[0]);
                swap(x_true[1], x_false[1]);
            }
            if (A > C) {
                swap(y_true[0], y_false[0]);
                swap(y_true[1], y_false[1]);
            }

            //(A & D) | (B & C)
            //(A & B) | (A & C) | (B & D) | (C & D)

            //             T  F    T     F        T  F      T     F
            // 1 1 6 6 -> {1, 2}, {2001, 2002}, {11, 12}, {2011, 2012}
            // 6 6 1 1 -> {11, 12}, {2011, 2012}, {1, 2}, {2001, 2002}

            if (A == C) { //x축 같으니 y 바꾸기
                adj[x_false[0]].push_back(x_true[1]); //notA -> C
                adj[x_false[1]].push_back(x_true[0]); //notC -> A  
            } else if (B == D) { //이하동일
                adj[y_false[1]].push_back(y_true[0]); //notD -> B
                adj[y_false[0]].push_back(y_true[1]); //notB -> D
            } else {
                adj[x_false[0]].push_back(x_true[1]); //notA -> C
                adj[x_false[1]].push_back(x_true[0]); //notC -> A

                adj[x_false[0]].push_back(y_true[0]); //notA -> B
                adj[y_false[0]].push_back(x_true[0]); //notB -> A

                adj[y_false[1]].push_back(y_true[0]); //notD -> B
                adj[y_false[0]].push_back(y_true[1]); //notB -> D

                adj[y_false[1]].push_back(x_true[1]); //notD -> C
                adj[x_false[1]].push_back(y_true[1]); //notC -> D
            }
        }

        // for (int i = 1; i <= 4000; i++) {
        //     for (auto e : adj[i]) {
        //         cout << i << " " << e << endl;
        //     }
        // }

        for (int i = 0; i <= 4000; i++) {
            if (!parent[i]) {
                dfs(i);
            }
        }

        bool flag = true;
        for (int i = 1; i <= 4000; i+=2) {
            if (sccId[i] == sccId[i + 1]) { //not PARENT
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}