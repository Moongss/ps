#include <iostream>

int N;
int a[300][300];
int b[300][300];

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> b[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool flag = false;
            for (int k = 0; k < N; k++) {
                if (a[i][k] == 1 && b[k][j] == 1) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                result++;
        }
    }

    std::cout << result << std::endl;
    return 0;
}