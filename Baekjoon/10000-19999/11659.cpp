#include <iostream>

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M;
    int start, dest;
    int input;
    int sumList[100001] = {0, };

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        std::cin >> input;
        sumList[i] = sumList[i - 1] + input;
    }

    for (int i = 0; i < M; i++) {
        std::cin >> start >> dest;
        std::cout << sumList[dest] - sumList[start - 1] << "\n";
    }

    return 0;
}