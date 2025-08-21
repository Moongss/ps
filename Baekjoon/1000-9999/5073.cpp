#include <iostream>

int main() {
    int a, b, c;

    while (true) {
        std::cin >> a >> b >> c;
        if (a + b + c == 0)
            break;

        if (a + b <= c || a + c <= b || b + c <= a)
            std::cout << "Invalid\n";
        else if (a == b && b == c)
            std::cout << "Equilateral\n";
        else if (a == b || b == c || a == c)
            std::cout << "Isosceles\n";
        else 
            std::cout << "Scalene\n";
    }
    return 0;
}