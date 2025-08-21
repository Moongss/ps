#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
int A[11];
int operatorCnt[4];
ll calcMax = -1e9;
ll calcMin = 1e9;

void solve(int idx, ll calc) {
    if (idx == N) {
        calcMax = max(calcMax, calc);
        calcMin = min(calcMin, calc);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operatorCnt[i]) {
            operatorCnt[i]--;
            if (i == 0) solve(idx + 1, calc + A[idx]);
            if (i == 1) solve(idx + 1, calc - A[idx]);
            if (i == 2) solve(idx + 1, calc * A[idx]);
            if (i == 3) solve(idx + 1, calc / A[idx]);
            operatorCnt[i]++;
        }
    }
}
int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {cin >> A[i];}
    for (int i = 0; i < 4; i++) {cin >> operatorCnt[i];}

    solve(1, A[0]);
    cout << calcMax << endl << calcMin << endl;
    return 0;
}