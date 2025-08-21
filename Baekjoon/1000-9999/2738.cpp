#include <iostream>

int A[100][100];
int N, M;

int main() {
    std::cin >> N >> M;

    int t = 2;
    int tmp;
    while (t--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cin >> tmp;
                A[i][j] += tmp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;

    }
    return 0;
}