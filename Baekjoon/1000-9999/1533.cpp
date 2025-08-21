#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int S, E, T;
ll arr[10][10];
ll tmp[10][10];

void printarr(ll arr[10][10]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void matmul(ll dest[10][10], ll src[10][10]) {
    ll tmp[10][10];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[i][j] += (dest[i][k] * src[k][j]) % 1000003;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dest[i][j] = tmp[i][j] % 1000003;
            cout << dest[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    fastio;
    cin >> N >> S >> E >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]);
            if (arr[i][j]) arr[i][j] = tmp[i][j] = 1;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        cout << "COUNT  : " << i + 1 << endl;
        matmul(arr, tmp);
    }
    return 0;
}