#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N, K;
int arr[100001];
int pre[100001];

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    int max = INT_MIN;
    for (int i = K; i <= N; i++) {
        max = std::max(max, pre[i] - pre[i - K]);
    }
    cout << max << endl;
    return 0;
}