#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int func(int target, int base) {
    int ret = 0;
    while (target > 0) {
        ret += target % base;
        target /= base;
    }
    return ret;
}

int main() {
    fastio;

    for (int i = 1000; i < 10000; i++) {
        int dec = func(i, 10);
        int clock = func(i, 12);
        int hex = func(i, 16);

        if (dec == clock && clock == hex) cout << i << endl;
    }
    return 0;
}