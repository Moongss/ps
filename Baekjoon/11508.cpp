#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> A;

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i % 3 == 2) continue;
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}