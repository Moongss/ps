#include <iostream>
#include <string>

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    std::string str;

    std::cin >> str;
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[0] != str[i])
            flag = false;
    }
    if (flag) {
        std::cout << -1 << std::endl;
        return 0;
    }
    
    int start = 0;
    int end = str.length() - 1;
    while (start <= end) {
        if (str[start] != str[end]) {
            std::cout << str.length() << std::endl;
            return 0;
        }
        start++;
        end--;
    }
    std::cout << str.length() - 1 << std::endl;
    return 0;
}