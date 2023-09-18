#include <iostream>

int main() {
    int A, B;
    int K, X;



    std::cin >> A >> B;
    std::cin >> K >> X;

    int min = K-X;
    int max = K+X;
    int result = 0;
    for (int i = min; i <= max; i++) {
        if (A <= i && i <= B)
           result++; 
    }

    if (result == 0)
        std::cout << "IMPOSSIBLE" << std::endl;
    else
        std::cout << result << std::endl;

    return 0;
}

