#include <iostream>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M, input;
    std::map<int, int> numCountMap;
    
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        if (numCountMap.find(input) == numCountMap.end())
            numCountMap[input] = 1;
        else
            numCountMap[input]++;
    }

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> input;
        if (numCountMap.find(input) == numCountMap.end())
            std::cout << "0";
        else
            std::cout << numCountMap[input];
        std::cout << " ";
    }

    std::cout << "\n";
    return 0;
}