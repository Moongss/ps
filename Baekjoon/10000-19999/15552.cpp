#include <iostream>

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    
    int T, a, b;
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }
    return 0;
}