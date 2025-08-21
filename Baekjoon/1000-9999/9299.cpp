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
int arr[111];

int main() {
    fastio;

    int T; cin >> T;
    for (int j = 1; j <= T; j++) {
        memset(arr, 0, sizeof(arr));
        cin >> N;
        for (int i = N; i >= 0; i--) {
            cin >> arr[i];
        }

        cout << "Case " << j << ": " << N - 1 << " ";
        for (int i = N; i > 0; i--) {
            cout << arr[i] * (i) << " ";
        }
        cout << endl;
    }
    
    return 0;
}