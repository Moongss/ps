#include <iostream>

int N;
long arr[100000];

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    long d = arr[1] - arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] - arr[i - 1] != d) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] * -1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] * 2 << " ";
    }
    std::cout << std::endl;

    return 0;
}