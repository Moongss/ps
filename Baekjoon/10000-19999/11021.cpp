#include <iostream>

int T;
int A, B;
int main() {
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::cin >> A >> B;
        std::cout << "Case #" << i << ": " << A + B << '\n';
    }
    return 0;
}