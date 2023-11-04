#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int arr[9][9];

int main() {
    fastio;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }


    for (int i = 0; i < 9; i++) {
        bool rowCheck[10] = {0, };
        bool colCheck[10] = {0, };
        for (int j = 0; j < 9; j++) {
            rowCheck[arr[i][j]] = true;
            colCheck[arr[j][i]] = true; 
        }
        
        for (int j = 1; j <= 9; j++) {
            if (!rowCheck[j] || !colCheck[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    int dx[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
    int dy[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
    for (int k = 0; k < 9; k++) {
        bool boxCheck[10] = {0, };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                boxCheck[arr[i + dy[k]][j + dx[k]]] = true;
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (!boxCheck[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}