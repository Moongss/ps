#include <iostream>

int main() {
    int N, M;
    while (true) {
        std::cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        if (M % N == 0)
            std::cout << "factor\n";
        else if (N % M == 0)
            std::cout << "multiple\n";
        else
            std::cout << "neither\n";
    }
    return 0;
}