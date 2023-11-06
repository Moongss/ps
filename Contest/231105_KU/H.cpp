#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N, M, Q;
int arr[2001][2001];
ll pre[2001][2001];
int main() {
    fastio;
    
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++){ 
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            pre[i][j] = pre[i - 1][j] + arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            pre[i][j] += pre[i - 1][j - 1];
        }
    }

    while (Q--) {
        ll sum = 0;
        int W, P; cin >> W >> P;
        cout << pre[W][P] << endl;
    }
    return 0;
}