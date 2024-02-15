#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, X;
vector<int> v;

int gcd(int a, int b) {
    if (a < b) 
        return gcd(b, a);
    return b ? gcd(b, a % b) : a;
}

int main() {
    fastio;
    
    cin >> N; v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cin >> X;
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (gcd(X, v[i]) == 1) {
            sum += v[i];
            cnt++;
        }
    }

    printf("%.6Lf\n", (ld)sum / cnt);
    return 0;
}