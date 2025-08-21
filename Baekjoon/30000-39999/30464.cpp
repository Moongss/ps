#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int dp[200000];
int A[200000];
int N;
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int i = 0;
    dp[0] = 1;
    while (i < N - 1) {
        if (dp[i] && i + A[i] < N)
            dp[i + A[i]] = max(dp[i + A[i]], dp[i] + 1);
        i++;
    }

    i = N - 2;
    while (i >= 0) {
        if (dp[i] && i - A[i] >= 0)
            dp[i - A[i]] = max(dp[i - A[i]], dp[i] + 1);
        i--;
    }

    i = 0;
    while (i < N - 1) {
        if (dp[i] && i + A[i] < N)
            dp[i + A[i]] = max(dp[i + A[i]], dp[i] + 1);
        i++;
    }

    if (dp[N - 1] == 0)
        cout << -1 << endl;
    else
        cout << dp[N - 1] - 1 << endl;
    return 0;
}