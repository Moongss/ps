#include <iostream>
#include <vector>
#include <string>

std::vector<char> v[15];

int main() {
    std::string str;
    for (int i = 0; i < 5; i++) {
        std::cin >> str;
        for (int j = 0; j < str.length(); j++){
            v[j].push_back(str[j]);
        }
    }

    for (int i = 0; i < 15; i++) {
        for (auto ch : v[i]) {
            std::cout << ch;
        }
    }
    std::cout << std::endl;
    return 0;
}