#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int main() {
    fastio;
    
    int N; cin >> N;
    double ans = 1010101010;
    for (int i = 0; i < N; i++) {
        double x; cin >> x;
        ans = min(ans, x);
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}