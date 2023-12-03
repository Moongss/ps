#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

ll N, M, K;
const ll P = 1000000007;

ll fact[4000001];
ll power(ll num, ll x) {
    ll ret = 1;
    while (x) {
        if (x & 1) ret = ret * num % P;
        num = num * num % P;
        x >>= 1;
    }
    return ret;
}

int main() {
    fastio;
    cin >> M;

    fact[0] = 1;
    for (int i = 1; i <= 4000000; i++)
        fact[i] = (fact[i - 1] * i) % P;
    
    while (M--) {
        cin >> N >> K;
        cout << (fact[N] % P) * power((fact[K] * fact[N-K]) % P, P - 2) % P << endl;
    }
    return 0;
}