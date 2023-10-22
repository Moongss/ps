#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

bool isPrime(ll num) {
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    fastio;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll num; cin >> num;
        if (num < 2) num = 2;
        while (num) {
            if (isPrime(num)) {
                cout << num << endl;
                break;
            }
            num++;
        }
    }
    return 0;
}