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
int arr[10];
int save[10];
int visited[10];

int res;
int cnt = 0;
void solve(int cur) {
    if (cur == N) {
        int sum = 0;
        for (int i = 1; i < N; i++) {
            sum += abs(save[i - 1] - save[i]);
        }
        res = max(res, sum);
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        save[cur] = arr[i];
        solve(cur + 1);
        save[cur] = 0;
        visited[i] = false;
    }
}
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    solve(0);
    cout << res << endl;
    return 0;
}