#include <iostream>
#include <cmath>

int main() {
    int x, y;
    double distance;
    int n;

    int caseNum;

    std::cin >> caseNum;

    for (int i = 0; i < caseNum; i++) {
        std::cin >> x >> y;
        distance = pow(y - x, 0.5);
        n = 2;

        if (y - x <= 3)
            std::cout << y - x << std::endl;
        else {
            while (distance > n) {
                n++;
            }
            if (distance < (2 * n - 1) / 2.0f)
                std::cout << 2 * n - 2 << std::endl;
            else
                std::cout << 2 * n - 1 << std::endl;
        }    
    }
    return 0;
}