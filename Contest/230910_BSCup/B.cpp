#include <iostream>

int main() {
    int T;
    int N;

    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::cin >> N;
        std::cout << "Case #" << i << ": ";
        if (4500 < N)
            std::cout << "Round 1\n";
        else if (1000 < N && N <= 4500)
            std::cout << "Round 2\n";
        else if (25 < N && N <= 1000)
            std::cout << "Round 3\n";
        else
            std::cout << "World Finals\n";
    }

    return 0;
}