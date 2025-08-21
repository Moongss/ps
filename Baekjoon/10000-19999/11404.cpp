#include <iostream>
#include <cstring>

#define INF 200000000

int movingCost[101][101] = {0, };
int N, M;

void initArray() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) movingCost[i][j] = INF;
        }
    }
}

void printArray() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (movingCost[i][j] == INF)
                std::cout << "0 ";
            else
                std::cout << movingCost[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int startPoint, endPoint, cost;
    
    std::cin >> N >> M;
    initArray();
    for (int i = 0; i < M; i++) {
        std::cin >> startPoint >> endPoint >> cost;
        if (movingCost[startPoint][endPoint] > cost)
            movingCost[startPoint][endPoint] = cost;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (j != k && movingCost[j][k] > movingCost[j][i] + movingCost[i][k])
                    movingCost[j][k] = movingCost[j][i] + movingCost[i][k];
            }
        }
    }
    printArray();

    return 0;
}