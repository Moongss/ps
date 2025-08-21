#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N; cin >> N;
    if (N % 6 != 2 && N % 6 != 3) {
        for (int i = 1; i <= N / 2; i++) {
            cout << i * 2 << endl;
        }
        for (int i = 1; i <= N / 2 + 1; i++) {
            cout << i * 2 - 1 << endl;
        }
    }
    if (N % 6 == 2) {
        //2468-1357, 
        for (int i = 1; i <= N / 2; i++) {
            cout << i * 2 << endl;
        }
        cout << 3 << endl;
        cout << 1 << endl;
        for (int i = 4; i <= (N + 1) / 2; i++) {
            cout << i * 2 - 1 << endl;
        }
        cout << 5 << endl;
    }
    if (N % 6 == 3) {
        for (int i = 2; i <= N / 2; i++) {
            cout << i * 2 << endl;
        }
        cout << 2 << endl;
        for (int i = 3; i <= (N + 1) / 2; i++) {
            cout << i * 2 - 1 << endl;
        }
        cout << 1 << endl;
        cout << 3 << endl;
    }
    return 0;
}