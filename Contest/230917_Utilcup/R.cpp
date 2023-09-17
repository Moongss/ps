#include <iostream>

int main() {
    int N;
    int A[1000] = {0, };
    int B[1000] = {0, };
    
    std::cin >> N;
    int result = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        if (A[i] <= B[i])
            result++;
    }
    std::cout << result << std::endl;
    return 0;

}