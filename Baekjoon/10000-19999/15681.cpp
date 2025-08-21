#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, R, Q;
bool visited[100001];
vector<int> v[100001];
int arr[100001];

int dfs(int s) {
    arr[s]++;
    visited[s] = true;

    for (auto &nxt : v[s]) {
        if (visited[nxt]) continue;
        arr[s] += dfs(nxt);
    }
    return arr[s];
}

int main() {
    fastio;
    
    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        int s, e; cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    dfs(R);
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        cout << arr[x] << endl;
    }
    return 0;
}