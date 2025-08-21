#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int dp[200004];
int A[200001];
ll sum = 0;
int main() {
    fastio;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i]; sum += A[i];
    }

    for (int i = 3; i <= N + 2; i++) {
        dp[i] = max(dp[i - 1], dp[i - 3] + (A[i] + A[i - 1] + A[i - 2]));
    }
    cout << dp[N + 2] + sum << endl;
    return 0;
}