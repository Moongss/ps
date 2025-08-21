#include <iostream>

int main() {
    long long N;
    bool arr[1000001] = {false, };
    long long X;
    long long max;

    std::cin >> N >> X;
    max = (N - 2) * (N - 1) / 2;
    if (X > max) {
        std::cout << -1 << std::endl;
        return 0;
    }

    long long tmp = X;
    for (int i = 1; i <= N - 2; i++) {
        if (tmp - ((N - 1) - i) >= 0) {
            arr[i] = true;
            tmp -= ((N - 1) - i); 
        }
    }

    std::cout << N << " ";
    for (int i = 1; i <= N - 1; i++) {
        if (arr[i]) std::cout << i << " ";
    } 
    for (int i = N - 1; i >= 1; i--) {
        if (!arr[i]) std::cout << i << " ";
    } 
    return 0;
}