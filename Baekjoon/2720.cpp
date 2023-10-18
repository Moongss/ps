#include <iostream>

int T, C;
int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    std::cin >> T;
    while (T--) {
        std::cin >> C;

        std::cout << C / 25 << " " 
                    << (C % 25) / 10 << " " 
                    << ((C % 25) % 10) / 5 << " " 
                    << (((C % 25) % 10) % 5) << "\n";
    }
    return 0;
}