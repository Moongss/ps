#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int sieve[4000001];
vector<int> prime;
void init() {
    for (int i = 2; i <= 4000000; i++) {
        sieve[i] = i;
    }
    for (int i = 2; i <= 4000000; i++) {
        if (!sieve[i]) continue;
        for (int j = i + i; j < 4000000; j += i) {
            sieve[j] = 0;
        }
    }
    for (int i = 2; i <= 4000000; i++) {
        if (sieve[i]) prime.push_back(i);
    }
}

int main() {
    fastio; init();

    int N; cin >> N;
    int l, r, sum, cnt;
    l = r = sum = cnt = 0;
    while (l <= r && r < prime.size()) {
        if (sum < N) {
            sum += prime[r++];
        } else if (sum > N) {
            sum -= prime[l++];
        } else {
            cnt++;
            sum += prime[r++];
            sum -= prime[l++];
        }
    }

    cout << cnt << endl;
    return 0;
}