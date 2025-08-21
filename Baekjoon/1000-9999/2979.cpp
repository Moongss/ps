#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int A, B, C;
int arr[101];
int main() {
    fastio;
    
    int A, B, C; cin >> A >> B >> C;
    for (int i = 1; i <= 3; i++) {
        int x, y; cin >> x >> y;
        for (int j = x; j < y; j++) {
            arr[j]++;
        }
    }

    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        if (arr[i] == 1) sum += A * arr[i];
        if (arr[i] == 2) sum += B * arr[i];
        if (arr[i] == 3) sum += C * arr[i];
    }
    cout << sum << endl;
    return 0;
}