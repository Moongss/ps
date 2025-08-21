#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a + b + c != 180)
        std::cout << "Error\n";
    else if (a == b && b == c)
        std::cout << "Equilateral\n";
    else if (a == b || b == c || a == c)
        std::cout << "Isosceles\n";
    else
        std::cout << "Scalene\n";

    return 0;
}