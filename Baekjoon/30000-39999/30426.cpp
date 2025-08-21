#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, K;
ll result = 0;
ll bits[1024];
int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        int curBits = 0;
        for (auto c : str) {
            curBits |= (1 << (c - '0'));
        }
        bits[curBits]++;
    }

    for (int i = 1; i < 1024; i++) {
        for (int j = i; j < 1024; j++) {
            if (__builtin_popcount(i | j) == K && bits[i] && bits[j]) {
                if (i != j) result += bits[i] * bits[j];
                else result += bits[i] * (bits[i] - 1) / 2;
            }
        }
    }
    cout << result << endl;
    return 0;
}