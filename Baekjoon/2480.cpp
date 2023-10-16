#include <iostream>

int a, b, c;
int main() {
    std::cin >> a >> b >> c;
    if (a == b && b == c)
        std::cout << 10000 + 1000 * a << std::endl;
    else if (a == b || a == c)
        std::cout << 1000 + 100 * a << std::endl;
    else if (b == c)
        std::cout << 1000 + 100 * b << std::endl;
    else
        std::cout << std::max(a, std::max(b, c)) * 100 << std::endl;

    return 0;
}