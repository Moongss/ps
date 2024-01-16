#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int a, b, c;
    scanf("%d + %d = %d", &a, &b, &c);
    cout << (a + b == c ? "YES" : "NO") << endl;
    return 0;
}