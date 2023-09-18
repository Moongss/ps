#include <iostream>

int main() {
    long long N, M;
    long long T, S;
    std::cin >> N >> M >> T >> S;

    long long Zip = N + ((N / 8) - 1) * S;
    long long Dok = M + ((M / 8) - 1) * (2 * T + S) + T;

    if (N % 8 != 0)
        Zip += S;
    if (M % 8 != 0)
        Dok += (S + T * 2);

    if (Zip < Dok)
        std::cout << "Zip\n" << Zip << std::endl;
    else
        std::cout << "Dok\n" << Dok << std::endl;
    return 0;
}