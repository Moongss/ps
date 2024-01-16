#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll N;
vector<ll> prime;

void getPrime(ll N) {
    for (ll i = 2; i <= 1000000; i++) {
        if (N % i) continue;
        else {
            prime.push_back(i);
            while (!(N % i)) 
                N /= i;
        }
    }
    if (N > 1) prime.push_back(N);
}

int main() {
    fastio;
    cin >> N; getPrime(N);

    ll result = 1;
    for (auto p : prime) {
        ll a = 0;
        while (!(N % p)) {
            a++;
            N /= p;
        }
        result *= (pow(p, a) - pow(p, a - 1));
    }
    cout << result << endl;
    return 0;
}