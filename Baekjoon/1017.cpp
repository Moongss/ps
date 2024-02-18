#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
bool isPrime[2020];
int prevNode[1010];
int flow[1010][1010];
int capacity[1010][1010];
vector<int> odd;
vector<int> even;
vector<int> adj[1010];

int s = 0; 
int e = 1001;
int firstElem;

void getSieve() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= 2000; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j <= 2000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void setFlow(int s, int e, int flow) {
    capacity[s][e] = flow;

    adj[s].push_back(e);
    adj[e].push_back(s);
}

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto nxt : adj[cur]) {
            if (prevNode[nxt] != -1) continue;
            if (capacity[cur][nxt] - flow[cur][nxt] <= 0) continue;

            prevNode[nxt] = cur;
            q.push(nxt);
            if (nxt == e) return;
        }
    }
}

int main() {
    fastio;
    
    getSieve();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (i == 0) firstElem = n;
        if (n % 2 == 0) even.push_back(n);
        else odd.push_back(n);
    }

    int s = 0;
    int e = 1006;

    if (firstElem % 2 == 0) {
        for (auto elem : even) {
            setFlow(s, elem, 1);
        }
        for (auto elem : odd) {
            setFlow(elem, e, 1);
        }
        for (auto evenElem : even) {
            for (auto oddElem : odd) {
                if (isPrime[evenElem + oddElem]) {
                    setFlow(evenElem, oddElem, 1);
                }
            }
        }
    }
    else {
        for (auto elem : odd) {
            setFlow(s, elem, 1);
        }
        for (auto elem : even) {
            setFlow(elem, e, 1);
        }
        for (auto oddElem : odd) {
            for (auto evenElem : even) {
                if (isPrime[oddElem + evenElem]) {
                    setFlow(oddElem, evenElem, 1);
                }
            }
        }
    }

    if (odd.size() != even.size()) {
        cout << -1 << endl;
        return 0;
    }

    set<int> result;
    for (auto targetElem : (firstElem % 2 == 0 ? odd : even)) {
        if (!isPrime[firstElem + targetElem]) continue;
        memset(flow, 0, sizeof(flow));
        flow[s][firstElem] = flow[firstElem][targetElem] = flow[targetElem][e] = 1; //8ms -> 4ms
        int cnt = 1;
        while (1) {
            bfs(s, e);
            if (prevNode[e] == -1) break;

            for (int i = e; i != s; i = prevNode[i]) {
                flow[prevNode[i]][i]++;
                flow[i][prevNode[i]]--;
            }
            cnt++;
        }
        if (cnt == N / 2)
            result.insert(targetElem);
    }

    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (auto e : result) {
            cout << e << " ";
        }
    }
    return 0;
}