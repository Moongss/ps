#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
ll A[4000], B[4000], C[4000], D[4000];
vector<ll> X, Y;
int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X.push_back(A[i] + B[j]);
            Y.push_back(C[i] + D[j]);
        }
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    ll sum = 0;
    for (auto elem : X) {
        sum += upper_bound(Y.begin(), Y.end(), -elem) - lower_bound(Y.begin(), Y.end(), -elem);
    }
    cout << sum << endl;
    return 0;
}