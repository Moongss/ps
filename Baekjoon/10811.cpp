#include <iostream>

int arr[101];
int tmp[101];

int main() {
    int N, M, a, b;

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    while (M--) {
        std::cin >> a >> b;
        for (int i = 1; i <= N; i++) {
            if (a <= i && i <= b) {
                tmp[i] = arr[a + b - i];
            } else {
                tmp[i] = arr[i];
            }
        }

        for (int i = 1; i <= N; i++) {
            arr[i] = tmp[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}