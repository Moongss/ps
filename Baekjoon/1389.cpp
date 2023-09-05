#include <iostream>
#include <cstring>

#define INF 42424242

int main() {
    int relationship[101][101];
    int N, M;
    int A, B;

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            relationship[i][j] = INF;
        }
    }

    for (int i = 1; i <= N; i++) {
        relationship[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        std::cin >> A >> B;
        relationship[A][B] = 1;
        relationship[B][A] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (relationship[j][k] > relationship[j][i] + relationship[i][k])
                    relationship[j][k] = relationship[j][i] + relationship[i][k];
            }
        }
    }

    int currentPath;
    int shortestPath = INF;
    int result = INF;
    for (int i = 1; i <= N; i++) {
        currentPath = 0;
        for (int j = 1; j <= N; j++)
            currentPath += relationship[i][j];
        if (shortestPath > currentPath) {
            shortestPath = currentPath;
            result = i;
        }
    }

    std::cout << result << std::endl;
    return 0;
}