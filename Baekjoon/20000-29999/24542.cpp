#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

#define MOD 1000000007

int N, M;
int parent[200001];
int treeSize[200001];

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
    int pX = getParent(x);
    int pY = getParent(y);

    parent[pY] = pX;
    treeSize[pX] += treeSize[pY];
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {parent[i] = i; treeSize[i] = 1;}
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        unionParent(a, b);
    }

    ll ret = 1;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            ret = ((ret % MOD) * (treeSize[i] % MOD)) % MOD;
        }
    }
    
    cout << ret << endl;
    return 0;
}