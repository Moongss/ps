#include <iostream>

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    
    int T, a, b;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::cin >> a >> b;
        std::cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << std::endl;
    }
    return 0;
}