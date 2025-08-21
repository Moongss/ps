#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, M;
int arr[100][100];

void f(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            arr[i][j] = !arr[i][j];
        }
    }
}
int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    int result = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (arr[i][j] == 0) continue;
            else {
                result++;
                f(i, j);
            }
        }
    }
    cout << result << endl;
    return 0;
}