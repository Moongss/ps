#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

int src, dest;
bool isVisited[10000] = {0, };

int calculateD(int num) {
    return (num * 2) % 10000;
}

int calculateS(int num) {
    return (num == 0) ? 9999 : num - 1;
}

int calculateL(int num) {
    num = (num % 1000) * 10 + num / 1000;
    return num;
}

int calculateR(int num) {
    num = (num % 10) * 1000 + num / 10;
    return num;
}

void solve() {
    std::queue<std::pair<int, std::string> >calculateQueue;
    std::pair<int, std::string> currentPair; //num, log;
    calculateQueue.push({src, ""});
    while (!calculateQueue.empty()) {
        currentPair = calculateQueue.front();
        calculateQueue.pop();
        
        if (currentPair.first == dest) 
            break;
        else {
            if (!isVisited[calculateD(currentPair.first)]) {
                isVisited[calculateD(currentPair.first)] = true;
                calculateQueue.push({calculateD(currentPair.first), currentPair.second + "D"});
            }

            if (!isVisited[calculateS(currentPair.first)]) {
                isVisited[calculateS(currentPair.first)] = true;
                calculateQueue.push({calculateS(currentPair.first), currentPair.second + "S"});
            }

            if (!isVisited[calculateL(currentPair.first)]) {
                isVisited[calculateL(currentPair.first)] = true;
                calculateQueue.push({calculateL(currentPair.first), currentPair.second + "L"});
            }

            if (!isVisited[calculateR(currentPair.first)]) {
                isVisited[calculateR(currentPair.first)] = true;
                calculateQueue.push({calculateR(currentPair.first), currentPair.second + "R"});
            }
        }
    }

    std::cout << currentPair.second << std::endl;
}

void init() {
    for (int i = 0; i < 10000; i++)
        isVisited[i] = false;
}

int main() {
    int T;

    // int num = 123;
    // std::cout << "DEBUG: L(1258): " << calculateL(num) << std::endl;
    // std::cout << "DEBUG: L(1258): " << calculateR(num) << std::endl;
    // std::cout << "DEBUG: L(1258): " << calculateR(calculateR(num)) << std::endl;
    // std::cout << "DEBUG: L(1258): " << calculateR(calculateR(calculateR(num))) << std::endl;
    // std::cout << "DEBUG: L(1258): " << calculateR(calculateR(calculateR(calculateR(num)))) << std::endl;
    // std::cout << "DEBUG: R(1258): " << calculateR(num) << std::endl;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> src >> dest;
        init();   
        solve();
    }

    return 0;
}