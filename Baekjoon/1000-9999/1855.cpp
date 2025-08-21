#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

char arr[200][200];
int main() {
    fastio;
    
    int N; cin >> N;
    string str; cin >> str;
    for (int i = 0; i < str.length() / N; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 2 == 0) {
                arr[i][j] = str[i * N + j];
            } else {
                arr[i][j] = str[i * N + (N - j - 1)];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < str.length() / N; j++) {
            cout << arr[j][i];
        }
    }
    cout << endl;
    return 0;
}