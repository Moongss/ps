#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
int arr[200000];
int ans = -1;

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            int cnt = 0;
            for (int k = 0; k < N; k++) {
                if (arr[k] == i || arr[k] == j) {
                    cnt++;
                } else {
                    ans = max(ans, cnt);
                    cnt = 0;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}