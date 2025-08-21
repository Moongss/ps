#include <iostream>

int N;

int main() {
    std::cin >> N;
    
    for (int i = 4; i <= N; i+=4) {
        std::cout << "long ";
    }
    std::cout << "int\n";
    return 0;
}