#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    fastio;
    ll N; cin >> N;

    int cnt = 0;
    for (int i = 1; i * i <= N; i++) {
        cnt++;
    }   
    cout << cnt << endl;
    return 0;
}