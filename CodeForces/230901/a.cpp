#include <iostream>
#include <string>

int N;
std::string str;

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> str;

        for (int i = 0; i < 10; i++) {
            if (str[i] == '1') {
                std::cout << 13 << std::endl;
                break;
            }
            else if (str[i] == '3') {
                std::cout << 31 << std::endl;
                break;
            }
        }
    }  
    return 0;  
}