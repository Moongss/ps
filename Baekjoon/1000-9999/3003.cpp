#include <iostream>

int main() {
    int k, q, l, b, n, p;

    std::cin >> k >> q >> l >> b >> n >> p;
    std::cout << 1 - k << " " <<
                 1 - q << " " <<
                 2 - l << " " <<
                 2 - b << " " <<
                 2 - n << " " <<
                 8 - p << std::endl;

    return 0;
}