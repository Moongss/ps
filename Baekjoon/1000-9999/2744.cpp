#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cin >> str;
    
    for(int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') 
            std::cout << (char)(str[i] - 'A' + 'a');
        else if (str[i] >= 'a' && str[i] <= 'z')
            std::cout << (char)(str[i] - 'a' + 'A');
        else
            std::cout << str[i];
    }
    return 0;
 }