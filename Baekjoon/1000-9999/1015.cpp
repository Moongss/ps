#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<int> A, B;

int main() {
    fastio;
    
    cin >> N;
    A.resize(N + 1); B.resize(N + 1, -1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for (int j = 1; j <= 1000; j++) {
        for (int i = 0; i < N; i++) {
            if (A[i] == j && B[i] < 0) {
                B[i] = cnt;
                cnt++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}