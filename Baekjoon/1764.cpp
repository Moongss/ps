#include <iostream>
#include <string>
#include <map>

int main() {
    int count = 0;
    int N, M;
    std::map<std::string, int> personList;
    std::string name;

    std::cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        std::cin >> name;
        personList[name]++;
        if (personList[name] == 2)
            count++;
    }

    std::cout << count << std::endl;
    for(std::map<std::string, int>::iterator iter = personList.begin(); iter != personList.end(); iter++){
        if (iter->second == 2)
            std::cout << iter->first << std::endl;
    }
    
    return 0;

}