#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T;
int N, M;
int divCnt[10001];

void getDivisor() {
    divCnt[1] = 0;
    for (int i = 2; i <= 10000; i++) {
        int tmp = i;
        for (int j = 2; j * j <= i; j++) {
            while (tmp % j == 0) {
                tmp /= j;
                divCnt[i]++;
            }
        }
        if (tmp > 1) divCnt[i]++;
    }
}

int main() {
    fastio;
    
    getDivisor();
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N >> M;
        int result = 0;
        for (int j = 0; j < N; j++) {
            int rowSum = 0;
            for (int k = 0; k < M; k++) {
                int x; cin >> x; 
                rowSum += divCnt[x];
            }
            result ^= rowSum;
        }
        cout << "Case #" << i << ": " << (result ? "YES" : "NO") << endl;
    }
    return 0;
}