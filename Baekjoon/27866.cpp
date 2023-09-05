#include <iostream>
#include <string>

int main(){
    int idx;
    std::string str;
    
    std::cin >> str;
    std::cin >> idx;
    
    std::cout << str[idx - 1] << std::endl;
    return 0;
}