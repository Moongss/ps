#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int K, N;
int x, y;
int arr[129][129] = {0, };

int cnt = 1;
int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};
void solve(int s, int e, int N, pair<int, int> spout) {
    if (N == 2) {
        for (int i = 0; i < 4; i++) {
            if (arr[s + dx[i]][e + dy[i]] == 0)
                arr[s + dx[i]][e + dy[i]] = cnt;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextN = N / 2;
        int nextS = s + (dx[i] * nextN);
        int nextE = e + (dy[i] * nextN);

        if (nextS <= spout.first && spout.first < nextS + nextN &&
            nextE <= spout.second && spout.second < nextE + nextN) {
            continue;
        } else {
            pair dummySpout = {nextN + dx[i], nextN + dy[i]};
            arr[s + dummySpout.first - 1][e + dummySpout.second - 1] = cnt;
        }
    }

    for (int i = 0; i < 4; i++) {
        cnt++;
        int nextN = N / 2;
        int nextS = s + (dx[i] * nextN);
        int nextE = e + (dy[i] * nextN);
        if (nextS <= spout.first && spout.first < nextS + nextN &&
            nextE <= spout.second && spout.second < nextE + nextN) {
            solve(nextS, nextE, nextN, spout);
        } else {
            pair dummySpout = {s + nextN + dx[i] - 1, e + nextN + dy[i] - 1};
            solve(nextS, nextE, nextN, dummySpout);
        }
    }
}

int main() {
    fastio;
    
    cin >> K;
    cin >> x >> y;

    N = (1 << K);
    arr[N - y + 1][x] = -1;
    solve(1, 1, N, {N - y + 1, x});

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}