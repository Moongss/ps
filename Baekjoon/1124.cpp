#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int A, B;
int ans = 0;
bool sieve[100001];

void getSieve() {
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) {
            for (int j = i * 2; j <= 100000; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    fastio;
    getSieve();

    cin >> A >> B;
    for (int i = A; i <= B; i++) {
        if (sieve[i]) continue;
        int tmp = 0;
        int num = i;
        for (int j = 2; j * j <= i; j++) { 
            while (num % j == 0) {
                tmp++; num /= j;
            }
        }
        if (num > 1) tmp++;
        if (sieve[tmp]) ans++;
    }
    cout << ans << endl;
    return 0;
}