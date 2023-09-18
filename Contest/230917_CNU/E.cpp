#include <iostream>

int main() {
    int N;

    int A[100];
    int B[100];
    
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        if (A[i] < B[i])
            result += B[i] - A[i];
    }

    std::cout << result << std::endl;
    return 0;
}