#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

ll A, B;
int sieve[10000001];

void setSieve() {
    for (int i = 2; i <= 1e7; i++) {
        sieve[i] = i;
    }
    for (int i = 2; i <= 1e7; i++) {
        if (!sieve[i]) continue;
        for (int j = i + i; j <= 1e7; j+=i) {
            sieve[j] = 0;
        }
    }
}

int main() {
    fastio;
    
    setSieve();
    cin >> A >> B;
    ll sum = 0;
    for (ll i = 2; i <= 1e7; i++) {
        if (!sieve[i]) continue;
        if (i * i > B) break;

        ll tmp = i * i;
        while (tmp <= B) {
            if (tmp >= A) sum++;
            if (tmp > LLONG_MAX / i) break;
            tmp *= i;
        }
    }
    cout << sum << endl;
    return 0;
}