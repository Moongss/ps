#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int cnt = 0;
int arr[9][9];

int main() {
    fastio;
    
    cin >> N;
    while (N--) {
        cnt++;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> arr[i][j];
            }
        }
        
        bool flag = true;
        for (int i = 0; i < 9; i++) {
            set<int> row;
            set<int> col;
            for (int j = 0; j < 9; j++) {
                row.insert(arr[i][j]);
                col.insert(arr[j][i]);
            }

            if (row.size() != 9 || col.size() != 9)
                flag = false;
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<int> box;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        box.insert(arr[k][l]);
                    }
                }
                if (box.size() != 9)
                    flag = false;
            }
        }
        cout << "Case " << cnt << ": " << (flag ? "CORRECT" : "INCORRECT") << endl;
    }
    return 0;
}