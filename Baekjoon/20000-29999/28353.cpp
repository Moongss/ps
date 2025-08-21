#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, K;
vector<int> W;

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int w; cin >> w;
        W.push_back(w);
    }

    sort(W.begin(), W.end());
    int s = 0;
    int e = N - 1;
    int result = 0;
    while (s < e) {
        if (W[s] + W[e] <= K) {
            result++;
            s++; e--;
        } else {
            e--;
        }
    }
    cout << result << endl;
    return 0;
}