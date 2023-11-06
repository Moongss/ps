#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N, L; cin >> N >> L;

    for (int i = 0; i < L - 1; i++) {
        cout << "1";
    }
    cout << N << endl;
    return 0;
}