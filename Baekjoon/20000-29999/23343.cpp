#include <iostream>
#include <string>

std::string a;
std::string b;

bool isNum(std::string a) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] < '0' || a[i] > '9')
            return false;
    }
    return true;
}

int main() {
    std::cin >> a >> b;
    
    if (!isNum(a) || !isNum(b)) {
        std::cout << "NaN\n";
        return 0;
    } else {
        std::cout << std::atoi(a.c_str()) - std::atoi(b.c_str()) << std::endl;
    }
    return 0;
}