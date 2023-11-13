#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N; cin >> N;
    
    for (int i = 1; i <= (N + 1) / 2; i++) {
        cout << i * 2 - 1 << " ";
    }
    for (int i = N / 2; i >= 1; i--) {
        cout << i * 2 << " ";
    }
    cout << endl;
    return 0;
}