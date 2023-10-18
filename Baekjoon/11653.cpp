#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int p = 2;
    while (N > 1) {
        while (N % p == 0) {
            N /= p;
            std::cout << p << std::endl;
        }
        p++;
    }
    return 0;
}