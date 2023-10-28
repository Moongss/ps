#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N, M;
ll cnt[1000];
ll pre[1000001];
ll result = 0;

int main() {
    fastio;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
        pre[i] %= M;
        cnt[pre[i]]++;

        if (pre[i] == 0)
            result++;
    }

    for (int i = 0; i <= M; i++) {
        result += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    cout << result << endl;
    return 0;

}