#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


bool sieve[1001];
vector<int> pv;

void getSieve() {
    memset(sieve, true, sizeof(sieve));
    for (int i = 2; i <= 1000; i++) {
        if (sieve[i]) {
            for (int j = i + i; j <= 1000; j+=i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = 2; i <= 1000; i++) {
        if (sieve[i]) pv.push_back(i);
    }
}
int main() {
    fastio;
    
    getSieve();
    int N; cin >> N;
    int cnt = 0;

    for (int &x : pv) {
        while (N % x == 0) {
            N /= x;
            cnt++;
        }
    }
    if (N > 1) cnt++;

    int result = log2(cnt);
    cout << result << endl;
    return 0;
}