#include <iostream>
#include <map>
#include <string>

int main() {
    int N;
    int M;
    int total = 1;
    std::string _, category;
    std::map<std::string, int> wearCategory;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> M;
        for (int j = 0; j < M; j++) {
            std::cin >> _ >> category;
            wearCategory[category]++;
        }

        for (std::map<std::string, int>::iterator iter = wearCategory.begin(); iter != wearCategory.end(); iter++) {
            total *= (iter->second + 1);

        }
        std::cout << total - 1 << std::endl;
        wearCategory.clear();
        total = 1;
    }

    return 0;
}