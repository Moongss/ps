#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    int N; cin >> N;
    int result = 1;
    for (int i = 0; i < N; i++) {result *= 2;}
    cout << result << endl;
    return 0;
}