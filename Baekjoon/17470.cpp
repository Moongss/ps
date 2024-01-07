#include <bits/stdc++.h>

#define endl '\n';
using namespace std;

int N, M, R;
int max;
int inputArr[100][100];
int result[100][100];

int rotation[100][100] = { // 4x4
    {0, 1, 4, 5},
    {2, 3, 6, 7},
    {8, 9, 12, 13},
    {10, 11, 14, 15},
};

int rotateCnt = 0;
int operCnt[7];
int tmp2[100][100];

void rotateArray2(int flag) {
    if (flag == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M / 2; j++) {
                int tmp = inputArr[i][j];
                inputArr[i][j] = inputArr[i][M - j - 1];
                inputArr[i][M - j - 1] = tmp;
            }
        }
        return;
    } else if (flag == 1) {
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < M; j++) {
                int tmp = inputArr[i][j];
                inputArr[i][j] = inputArr[N - i - 1][j];
                inputArr[N - i - 1][j] = tmp;
            }
        }
        return;
    } else if (flag == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp2[j][N - i - 1] = inputArr[i][j]; // 0 위치 바꾸기
            }
        }
        int temp = N;
        N = M;
        M = temp;
    } else if (flag == 4) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp2[M - j - 1][i] = inputArr[i][j];
            }
        }
        int temp = N;
        N = M;
        M = temp;
    } else if (flag == 5) {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < N / 2; i++) {
                for (int j = 0; j < M / 2; j++) {
                    if (k == 0)
                        tmp2[i][j] = inputArr[N / 2 + i][j];
                    if (k == 1)
                        tmp2[i][M / 2 + j] = inputArr[i][j];
                    if (k == 2)
                        tmp2[N / 2 + i][M / 2 + j] = inputArr[i][M / 2 + j];
                    if (k == 3)
                        tmp2[N / 2 + i][j] = inputArr[N / 2 + i][M / 2 + j];
                }
            }
        }
    } else {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < N / 2; i++) {
                for (int j = 0; j < M / 2; j++) {
                    if (k == 0)
                        tmp2[i][j] = inputArr[i][M / 2 + j];
                    if (k == 1)
                        tmp2[i][M / 2 + j] = inputArr[N / 2 + i][M / 2 + j];
                    if (k == 2)
                        tmp2[N / 2 + i][M / 2 + j] = inputArr[N / 2 + i][j];
                    if (k == 3)
                        tmp2[N / 2 + i][j] = inputArr[i][j];
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            inputArr[i][j] = tmp2[i][j];
        }
    }
}

void rotateArray(int N, int M, int flag, int arr[100][100]) {
    int tmp[100][100];
    memset(tmp, 0, sizeof(tmp));
    if (flag == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M / 2; j++) {
                int tmp = arr[i][j];
                arr[i][j] = arr[i][M - j - 1];
                arr[i][M - j - 1] = tmp;
            }
        }
        return;
    } else if (flag == 1) {
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < M; j++) {
                int tmp = arr[i][j];
                arr[i][j] = arr[N - i - 1][j];
                arr[N - i - 1][j] = tmp;
            }
        }
        return;
    } else if (flag == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[j][N - i - 1] = arr[i][j]; // 0 위치 바꾸기
            }
        }
        int temp = N;
        N = M;
        M = temp;
    } else if (flag == 4) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[M - j - 1][i] = arr[i][j];
            }
        }
        int temp = N;
        N = M;
        M = temp;
    } else if (flag == 5) {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < N / 2; i++) {
                for (int j = 0; j < M / 2; j++) {
                    if (k == 0)
                        tmp[i][j] = arr[N / 2 + i][j];
                    if (k == 1)
                        tmp[i][M / 2 + j] = arr[i][j];
                    if (k == 2)
                        tmp[N / 2 + i][M / 2 + j] = arr[i][M / 2 + j];
                    if (k == 3)
                        tmp[N / 2 + i][j] = arr[N / 2 + i][M / 2 + j];
                }
            }
        }
    } else {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < N / 2; i++) {
                for (int j = 0; j < M / 2; j++) {
                    if (k == 0)
                        tmp[i][j] = arr[i][M / 2 + j];
                    if (k == 1)
                        tmp[i][M / 2 + j] = arr[N / 2 + i][M / 2 + j];
                    if (k == 2)
                        tmp[N / 2 + i][M / 2 + j] = arr[N / 2 + i][j];
                    if (k == 3)
                        tmp[N / 2 + i][j] = arr[i][j];
                }
            }
        }
    }
    cout << "N : " << N << ", M : " << M << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = tmp[i][j];
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }
}

void mappingArray(int r, int c) {
    int test[100][100];
    memset(test, 0, sizeof(test));
    // cout << "mapping Array : " << "r : " << r << ", c : " << c << endl;
    for (int i = r; i < N / 2 + r; i++) {
        for (int j = c; j < M / 2 + c; j++) {
            test[i][j] = inputArr[i][j];
        }
    }

    // cout << "test" << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << test[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (rotation[0][0] % 4 == 0 && rotation[0][1] % 4 == 1) {
        // cout << "DEBUG 1" << endl;

        int loopCnt = 0;
        if (rotation[0][0] / 4 == 0) loopCnt = 0;
        else if (rotation[0][0] / 4 == 2) loopCnt = 1;
        else if (rotation[0][0] / 4 == 3) loopCnt = 2;
        else if (rotation[0][0] / 4 == 1) loopCnt = 3;
        
        for (int i = 0; i < loopCnt; i++) {
            rotateArray(N, M, 5, test);
        }
    }
    if (rotation[0][0] % 4 == 1 && rotation[0][1] % 4 == 0) {
        // cout << "DEBUG 2" << endl;
        rotateArray(N, M, 2, test);
    }
    if (rotation[1][1] % 4 == 0 && rotation[1][0] % 4 == 1) {
        // cout << "DEBUG 3" << endl;
        rotateArray(N, M, 3, test);
        rotateArray(M, N, 3, test);
    }
    if (rotation[1][1] % 4 == 1 && rotation[1][0] % 4 == 0) {
        // cout << "DEBUG 4" << endl;
        rotateArray(N, M, 1, test);
    }
    if (rotation[1][1] % 4 == 0 && rotation[0][1] % 4 == 1) {
        // cout << "DEBUG 5" << endl;
        // rotateArray(N, M, 3, test);

        rotateArray(N, M, 4, test);
        rotateArray(M, N, 1, test);   
    }
    if (rotation[1][1] % 4 == 1 && rotation[0][1] % 4 == 0) {
        // cout << "DEBUG 6" << endl;
        rotateArray(N, M, 3, test);
    }
    if (rotation[0][0] % 4 == 0 && rotation[1][0] % 4 == 1) {
        // cout << "DEBUG 7" << endl;
        rotateArray(N, M, 3, test);
        rotateArray(M, N, 1, test);
    }
    if (rotation[0][0] % 4 == 1 && rotation[1][0] % 4 == 0) {
        // cout << "DEBUG 8" << endl;
        rotateArray(N, M, 4, test);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (test[i][j])
                result[i][j] = test[i][j];
        }
    }
    // cout << "MAPPING RESULT\n";
    // if (rotateCnt) {
    //     for (int i = 0; i < M; i++) {
    //         for (int j = 0; j < N; j++) {
    //             cout << result[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // } else {
    //     for (int i = 0; i < N; i++) {
    //         for (int j = 0; j < M; j++) {
    //             cout << result[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
}

#define fastio cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    fastio
    std::cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> inputArr[i][j];
        }
    }

    int operate;
    int leftCnt = 0;
    int rightCnt = 0;
    for (int i = 0; i < R; i++) {
        std::cin >> operate;
        if (operate == 3) leftCnt++;
        else if (operate == 4) rightCnt++;

        if (N >= 4 && M >= 4) {
            rotateArray(4, 4, operate, rotation);
        }
        else {
            rotateArray2(operate);
        }
    }

    rotateCnt = abs(leftCnt - rightCnt) % 2;
    if (N >= 4 && M >= 4) {
        mappingArray(0, 0);
        mappingArray(N / 2, 0);
        mappingArray(0, M / 2);
        mappingArray(N / 2, M / 2);

        if (rotateCnt) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << inputArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}