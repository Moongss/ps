#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int arr[8][8];
int tmp[8][8]; 

int main() {
    fastio;
    
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) cnt++;
        }
    }

    int ans = min({cnt, N*N - cnt});
    for (int i = 0; i < (1 << (N+1) - 1); i++) {
        for (int j = 0; j < (1 << (N+1) - 1); j++) {
            memcpy(tmp, arr, sizeof(arr));

            int a, b; a = b = 0;
            for (int k = 0; k < N; k++) {
                if (i & (1 << k)) {
                    a++; b++;
                    for (int l = 0; l < N; l++) {
                        tmp[k][l] = !tmp[k][l];
                    }
                }
            }
            for (int k = 0; k < N; k++) {
                if (j & (1 << k)) {
                    a++; b++;
                    for (int l = 0; l < N; l++) {
                        tmp[l][k] = !tmp[l][k];
                    }
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (tmp[i][j]) a++; //상관없을듯
                    else b++;
                }
            }

            ans = min({ans, a, b});
        }
    }    

    cout << ans << endl;
    return 0;
}