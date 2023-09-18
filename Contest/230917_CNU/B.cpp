#include <iostream>

int main() {
    int A, B;

    std::cin >> A >> B;
    if (A > B) {
        std::cout << 2 * B + 1 << std::endl;
    } else if (A == B) {
        std::cout << 2 * (B - 1) + 1 << std::endl;
    } else {
        std::cout << 2 * (A) - 1 << std::endl;
    }

    return 0;
}