#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll fibo[50];
int N;

int main() {
    fastio;
    
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 45; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    cin >> N;
    cout << fibo[N - 1] << " " << fibo[N] << endl;
    return 0;
}