#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N, M; cin >> N >> M;
    int J; cin >> J;

    int start = 1;
    int end = M;
    int ans = 0;
    for (int i = 0; i < J; i++) {
        int a; cin >> a;
        if (start <= a && a <= end) continue;
        if (a < start) {
            ans += start - a;
            end -= start - a;
            start = a;
        } else {
            ans += a - end;
            start += a - end;
            end = a;
        }
    }   
    cout << ans << endl;
    return 0;
}