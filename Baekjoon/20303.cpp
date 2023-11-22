#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M, K;
int candy[30001];
int parents[30001];
int sum[30001];
int cry[30001];
int dp[3030];

int getParents(int x) {
    if (parents[x] == x) return x;
    return parents[x] = getParents(parents[x]);
}

void unionParents(int a, int b) {
    a = getParents(a);
    b = getParents(b);
    if (a < b) parents[b] = a;
    else parents[a] = b;
}

int main() {
    fastio;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> candy[i];
        parents[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        unionParents(a, b);
    }

    for (int i = 1; i <= N; i++) sum[getParents(i)] += candy[i];
    for (int i = 1; i <= N; i++) cry[getParents(i)]++;

    for (int i = 1; i <= N; i++) {
        for (int j = K - 1; j >= 0; j--) {
            if (getParents(i) == i && j >= cry[i])
                dp[j] = max(dp[j], dp[j - cry[i]] + sum[i]);
        }
    }

    cout << dp[K - 1] << endl;
    return 0;
}