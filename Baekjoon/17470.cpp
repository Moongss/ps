#include <iostream>

int N, M, R;
int max;
int arr[100][100];
int tmp[100][100];
int operCnt[7];

void modifyArray(int flag) {
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

int main() {
    std::cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> arr[i][j];
        }
    }

    int operate;
    for (int i = 0; i < R; i++) {
        std::cin >> operate;
        operCnt[operate]++;
    }

    operCnt[1] %= 2;
    operCnt[2] %= 2;
    operCnt[3] %= 4;
    operCnt[4] %= 4;
    operCnt[5] %= 4;
    operCnt[6] %= 4;

    for (int i = 1; i <= 6; i++) {
        while (operCnt[i]--) {
            modifyArray(i);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}