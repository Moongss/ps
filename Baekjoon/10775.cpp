#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, G;
int p[100001];

int find(int v) { 
    if (v == p[v]) return v;
    return p[v] = find(p[v]);
}

int main() {
    fastio;
    cin >> N >> G;
    iota(p, p + 100001, 0);

    for (int i = 0; i < G; i++) {
        int g; cin >> g;
        int parent = find(g);
        if (parent == 0) {cout << i << endl; return 0;}
        else p[parent] = find(parent - 1);
    }
    cout << G << endl;
    return 0;
}