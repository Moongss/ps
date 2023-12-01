#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M;
int shooter[100001];
int cnt = 1;
int in[100001], out[100001];

void dfs(int cur) {
    if (in[cur] == 0) {
        cnt++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (shooter[i] == cur) {
            dfs(i);
        }
    }
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> shooter[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        in[b]++;
        out[a]++;
    }
    return 0;
}