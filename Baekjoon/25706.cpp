#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
int dp[400000];
int arr[200000];
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = N - 1; i >= 0; i--) {
        dp[i] = dp[i + arr[i] + 1] + 1;
    }
    for (int i = 0; i < N; i++) cout << dp[i] << " ";
    return 0;
}