#include <iostream>
#include <algorithm>

int main() {
    int h, l, a, b;

    std::cin >> h >> l >> a >> b;

    if (h * 2 >= a && l >= b || h * 2 >= b && l >= a)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    return 0;
}