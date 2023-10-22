#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int sieve[250001];
void setSieve() {
    for (int i = 2; i <= 250000; i++) {
        sieve[i] = i;
    }
    for (int i = 2; i <= 250000; i++) {
        if (!sieve[i]) continue;
        for (int j = i + i; j <= 250000; j += i) {
            sieve[j] = 0;
        }
    }
}

int main() {
    fastio;
    setSieve();
    while (true) {
        int N; cin >> N;
        if (N == 0) break;

        int cnt = 0;
        for (int i = N + 1; i <= 2 * N; i++) {
            if (sieve[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}