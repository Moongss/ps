#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll N; 
bool isPrime[1000001];
vector<ll> p;
queue<ll> q;

void getSieve() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= 1000000; i++) {
        if (!isPrime[i]) continue;
        p.push_back(i);
        for (int j = 2 * i; j <= 1000000; j += i) {
            isPrime[j] = false;
        }
    }
}

void factorization() {
    ll tmp = N;
    for (ll i = 0; i < p.size() && p[i] <= tmp; i++) {
        while (tmp % p[i] == 0) {
            q.push(p[i]);
            tmp /= p[i];
        }
    }
    if (tmp > 1) q.push(tmp);

    if (q.size() == 1) cout << -1 << endl;
    else {
        while (!q.empty()) {
            if (q.size() <= 3) break;
            ll tmp = 1;
            tmp *= q.front(); q.pop();
            tmp *= q.front(); q.pop();
            cout << tmp << " ";
        }
        ll tmp = 1;
        while (!q.empty()) {
            tmp *= q.front(); q.pop();
        }
        cout << tmp << endl;
    }
}
int main() {
    fastio;
    
    cin >> N;
    getSieve();
    factorization();

    return 0;
}