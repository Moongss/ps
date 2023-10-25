#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N; cin >> N;
    ll result = 1;
    for (int i = 1; i <= N; i++) {
        result *= i;
    }
    cout << result << endl;
    return 0;
}