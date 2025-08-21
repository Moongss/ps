#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    fastio;
    int N; cin >> N;
    while (N--) {
        ld A, B; cin >> A >> B;
        printf("%.1Lf\n", abs(A - B));
    }
    return 0;
}