#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

string arr[11][11];
int main() {
    fastio;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 10; i++ ){
        bool rowFlag = true;
        bool colFlag = true;
        for (int j = 1; j < 10; j++) {
            if (arr[i][j] != arr[i][j - 1]) {
                rowFlag = false;
            }           
            if (arr[j][i] != arr[j - 1][i]) {
                colFlag = false;
            }
        }
        if (rowFlag || colFlag) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}