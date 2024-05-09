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
    
    pii result = {0, -1};
    for (int i = 1; i <= 5; i++) {
        int sum = 0;
        for (int j = 1; j <= 4; j++) {
            int x; cin >> x; sum += x;
        }
        if (result.second < sum) {
            result.first = i;
            result.second = sum;
        }
    }
    cout << result.first << " " << result.second << endl;
    return 0;
}