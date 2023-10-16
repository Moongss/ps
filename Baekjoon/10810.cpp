#include <iostream>

int arr[101];

int main() {
    int N, M, a, b;
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        int tmp;

        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    for (int i = 1; i <= N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}