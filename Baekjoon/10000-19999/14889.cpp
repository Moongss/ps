#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
int arr[20][20];
bool check[10];
ll result = 424242;

void solve(int idx, int cnt) {
    if (cnt == N / 2) {
        ll startTeamStat = 0;
        ll linkTeamStat = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (check[i] && check[j])
                    startTeamStat += arr[i][j] + arr[j][i];
                if (!check[i] && !check[j])
                    linkTeamStat += arr[i][j] + arr[j][i];
            }
        }
        result = min(result, abs(startTeamStat - linkTeamStat));
        return;
    }

    for (int i = idx; i < N; i++) {
        check[i] = true;
        solve(i + 1, cnt + 1);
        check[i] = false;
    }
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    solve(0, 0);
    cout << result << endl;
    return 0;
}