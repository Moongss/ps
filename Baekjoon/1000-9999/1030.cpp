#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int S, N, K;
ll R1, R2, C1, C2;
int margin;
ll sideLength;

bool isBlack(ll r, ll c, ll sideLength) {
    if (sideLength == 0) return false;
    if (margin * sideLength <= r && r < (N - margin) * sideLength &&
        margin * sideLength <= c && c < (N - margin) * sideLength)
        return true;
    
    return (isBlack(r % sideLength, c % sideLength, sideLength / N));
}

int main() {
    fastio;
    cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
    
    margin = (N - K) / 2;
    sideLength = 1;
    while (--S > 0) sideLength *= N;
    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << (isBlack(i, j, sideLength) ? 1 : 0);
        }
        cout << endl;
    }
    return 0;
}