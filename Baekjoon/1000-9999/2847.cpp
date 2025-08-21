#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> v;

int main() {
    fastio;
    
    cin >> N; 
    ll sum = 0;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> v[i];

    int minValue = v[N];
    for (int i = N - 1; i >= 1; i--) {
        if (minValue <= v[i]) {
            sum += (v[i] - minValue + 1);
        }

        minValue = min(minValue - 1, v[i]);
        v[i] = min(v[i], minValue - 1);
    }

    cout << sum << endl;
    return 0;
}