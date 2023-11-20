#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int arr[202][202];

int main() {
    fastio;
    int N, M;
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        string str; cin >> str;
        for (int j = 1; j <= N; j++) {
            arr[i][j] = str[j - 1] - '0';
        }
    }

    ld sum = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp = 0;
            int cnt = 0;
            if (i > 1) {tmp += abs(arr[i][j] - arr[i - 1][j]); cnt++;}
            if (i < M) {tmp += abs(arr[i][j] - arr[i + 1][j]); cnt++;}
            if (j > 1) {tmp += abs(arr[i][j] - arr[i][j - 1]); cnt++;}
            if (j < N) {tmp += abs(arr[i][j] - arr[i][j + 1]); cnt++;}
            sum += tmp * 1.0 / cnt;
        }
    }
    cout << fixed << setprecision(4) << sum;
    return 0;
}