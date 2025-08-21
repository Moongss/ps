#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
int arr[21][21];
void print() {
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
           cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;

}

void push(int dir) {
    if (dir == 0) {
        for (int i = 0; i < N; i++) {
            int zeroPos = 0;
            int nonZeroPos = 0;

            while (zeroPos < N && nonZeroPos < N) {
                if (arr[i][zeroPos] != 0) {
                    zeroPos++;
                    continue;
                }
                nonZeroPos = zeroPos + 1;
                while (nonZeroPos < N) {
                    if (arr[i][nonZeroPos] == 0) {
                        nonZeroPos++;
                        continue;
                    }
                    arr[i][zeroPos] = arr[i][nonZeroPos];
                    arr[i][nonZeroPos] = 0;
                    break;
                }
            }
        }
    }
    else if (dir == 1) {
        for (int i = 0; i < N; i++) {
            int zeroPos = N - 1;
            int nonZeroPos = N - 1;

            while (zeroPos >= 0 && nonZeroPos >= 0) {
                if (arr[i][zeroPos] != 0) {
                    zeroPos--;
                    continue;
                }
                nonZeroPos = zeroPos - 1;
                while (nonZeroPos >= 0) {
                    if (arr[i][nonZeroPos] == 0) {
                        nonZeroPos--;
                        continue;
                    }
                    arr[i][zeroPos] = arr[i][nonZeroPos];
                    arr[i][nonZeroPos] = 0;
                    break;
                }
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < N; i++) {
            int zeroPos = 0;
            int nonZeroPos = 0;

            while (zeroPos < N && nonZeroPos < N) {
                if (arr[zeroPos][i] != 0) {
                    zeroPos++;
                    continue;
                }
                nonZeroPos = zeroPos + 1;
                while (nonZeroPos < N) {
                    if (arr[nonZeroPos][i] == 0) {
                        nonZeroPos++;
                        continue;
                    }
                    arr[zeroPos][i] = arr[nonZeroPos][i];
                    arr[nonZeroPos][i] = 0;
                    break;
                }
            }
        }
    }
    else if (dir == 3) {
        for (int i = 0; i < N; i++) {
            int zeroPos = N - 1;
            int nonZeroPos = N - 1;

            while (zeroPos >= 0 && nonZeroPos >= 0) {
                if (arr[zeroPos][i] != 0) {
                    zeroPos--;
                    continue;
                }
                nonZeroPos = zeroPos - 1;
                while (nonZeroPos >= 0) {
                    if (arr[nonZeroPos][i] == 0) {
                        nonZeroPos--;
                        continue;
                    }
                    arr[zeroPos][i] = arr[nonZeroPos][i];
                    arr[nonZeroPos][i] = 0;
                    break;
                }
            }
        }
    }
}

int move(int dir) {
    
    if (dir == 0) {
        for (int i = 0; i < N; i++) {
            int target = -1;
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 0) continue;
                if (target == -1) {
                    target = j;
                    continue;
                }
                if (arr[i][target] == arr[i][j]) {
                    arr[i][target] *= 2;
                    arr[i][j] = 0;
                    target = -1;
                }
                else {
                    target = j;
                }
            }
        }
    }
    else if (dir == 1) {
        for (int i = 0; i < N; i++) {
            int target = -1;
            for (int j = N - 1; j >= 0; j--) {
                if (arr[i][j] == 0) continue;
                if (target == -1) {
                    target = j;
                    continue;
                }
                if (arr[i][target] == arr[i][j]) {
                    arr[i][target] *= 2;
                    arr[i][j] = 0;
                    target = -1;
                }
                else {
                    target = j;
                }
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < N; i++) {
            int target = -1;
            for (int j = 0; j < N; j++) {
                if (arr[j][i] == 0) continue;
                if (target == -1) {
                    target = j;
                    continue;
                }
                if (arr[target][i] == arr[j][i]) {
                    arr[target][i] *= 2;
                    arr[j][i] = 0;
                    target = -1;
                }
                else {
                    target = j;
                }
            }
        }
    }
    else if (dir == 3) {
        for (int i = 0; i < N; i++) {
            int target = -1;
            for (int j = N - 1; j >= 0; j--) {
                if (arr[j][i] == 0) continue;
                if (target == -1) {
                    target = j;
                    continue;
                }
                if (arr[target][i] == arr[j][i]) {
                    arr[target][i] *= 2;
                    arr[j][i] = 0;
                    target = -1;
                }
                else {
                    target = j;
                }
            }
        }
    }

    push(dir);

    int ret = 0;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            ret = max(ret, arr[i][j]);
    return ret;
}


int solve(int cnt) {
    if (cnt == 5) return 0;

    int save[21][21];
    int ret = 0;
    memcpy(save, arr, sizeof(arr));
    for (int i = 0; i < 4; i++) {
        ret = max(ret, move(i));

        // cout << "cnt : " << cnt << ", dir : " << i << endl;
        // print();

        ret = max(ret, solve(cnt + 1));
        memcpy(arr, save, sizeof(save));

        // if (cnt == 1) {
        //     cout << "복원" << endl;
        //     print();
        // }
    }
    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> arr[i][j];

    cout << solve(0) << endl;
    return 0;
}