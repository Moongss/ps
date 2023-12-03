#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
int popular = 0;
int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int p, c; cin >> p >> c;
        if (abs(popular - p) <= c)
            popular++;
    }
    cout << popular << endl;
    return 0;
}