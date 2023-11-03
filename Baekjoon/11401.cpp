#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

ll N, K;
ll P = 1000000007;

ll factorial(ll num) {
    ll result = 1;

    for (int i = 1; i <= num; i++) {
        result *= i;
        result %= P;
    }
    return result;
}

ll power(ll num, ll x) {
    if (x == 0)
        return 1;
    else if (x == 1)
        return num % P;
    else {
        ll tmp = power(num, x / 2) % P;
        if (x % 2)
            return (tmp * tmp % P) * (num % P) % P;
        else
            return tmp * tmp % P;
    }
}

int main() {
    fastio;
    cin >> N >> K;

    cout << (factorial(N) % P) * power((factorial(K) * factorial(N - K) % P), P - 2) % P << endl;
    return 0;
}