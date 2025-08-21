#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int sieve[1000000];
void setSieve() {
    for (int i = 2; i <= 1000000; i++) {
        sieve[i] = i;
    }
    for (int i = 2; i <= 1000000; i++) {
        if (!sieve[i]) continue;
        for (int j = i + i; j <= 1000000; j += i) {
            sieve[j] = 0;
        }
    }
}

int main() {
    fastio;
    setSieve();
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int cnt = 0;
        for (int i = 2; i <= N / 2; i++) {
            if (sieve[i] && sieve[N - i])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}