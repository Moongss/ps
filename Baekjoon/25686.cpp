#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
void solve(int s, int e, int d) {
    int num = (e - s) / d + 1;
    if (num < 2) {
        for (int i = s; i <= e; i += d)
            cout << i << " ";
        return;
    }

    if (num % 2 == 0) { 
        solve(s, e - d, 2 * d); 
        solve(s + d, e, 2 * d);
    } else {
        solve(s, e, 2 * d);
        solve(s + d, e - d, 2 * d);
    }
}

int main() {
    fastio;
    cin >> N; solve(1, N, 1);
    cout << endl;
    return 0;
}