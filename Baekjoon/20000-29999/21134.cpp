#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int arr[10];
int dp[10][10];
bool visited[10];
string s;
ll ans = 0x3f3f3f3f3f;

void solve(int cur) {
    if (cur > 9) {
        int pos[10][10]; memset(pos, 0, sizeof(pos));
        ll sum = s.length();

        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                pos[arr[i]][arr[j]] = abs(i - j);
                pos[arr[j]][arr[i]] = abs(i - j);
            }
        }

        sum += find(arr + 1, arr + 10, s[0] - '0') - (arr + 1);
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (dp[i][j] && pos[i][j]) {
                    sum += pos[i][j] * dp[i][j];
                }
            }
        }

        // 1 2 3 4 5 6 7 8 9
        // 2 3 4 5 6 7 8 9 1 
        // if (arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5 && arr[5] == 6 && arr[6] == 7 && arr[7] == 8 && arr[8] == 9 && arr[9] == 1) {
        //     cout << "=======\n";
        //     cout << find(arr + 1, arr + 10, s[0] - '0') - arr << endl;
        //     cout << "sum: " << sum << endl;
        //     cout << "arr: " << s[0] - '0' << " " << arr[s[0] - '0'] -  1 << endl;
        // }
        ans = min(ans, sum);
        // if (ans == sum) {
        //     for (int i = 1; i <= 9; i++) {
        //         cout << arr[i] << " ";
        //     }
        //     cout << endl;

        //     cout << find(arr + 1, arr + 10, s[0] - '0') - arr << endl;
        //     cout << "arr: " << s[0] - '0' << " " << arr[s[0] - '0'] - 1<< endl;
        //     for (int i = 1; i <= 9; i++) {
        //         for (int j = 1; j <= 9; j++) {
        //             if (dp[i][j]) {
        //                 cout << i << " " << j << " " << pos[i][j] << " " << dp[i][j] << endl;
        //                 sum += pos[i][j] * dp[i][j];
        //             }
        //         }
        //     }
        // }
        return;  
    }

    for (int i = 1; i <= 9; i++) {
        if (visited[i]) continue;
        visited[i] = true; 
        arr[cur] = i;
        solve(cur + 1);
        visited[i] = false;
    }
}

int main() {
    fastio;
    
    cin >> s;
    for (int i = 1; i < s.length(); i++) {
        dp[s[i - 1] - '0'][s[i] - '0']++;
    }
    solve(1);
    cout << ans << endl;
    return 0;
}