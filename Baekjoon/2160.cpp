#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
char arr[50][5][7];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 7; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    int ans = 424242;
    int a, b;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 7; l++) {
                    sum += (arr[i][k][l] != arr[j][k][l] ? 1 : 0);
                }
            }
            if (sum < ans) {
                ans = sum;
                a = i+1;
                b = j+1;
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}