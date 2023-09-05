#include <iostream>
#include <vector>
#include <algorithm>

int infectionCnt = 0;
bool isVisited[101] = {0, };
std::vector<int> connectionList[101];

void solve(int start) {
    isVisited[start] = true;

    for (int i = 0; i < connectionList[start].size(); i++) {
        int currentNode = connectionList[start][i];
        if (!isVisited[currentNode]) {
            infectionCnt++;
            solve(currentNode);
        }
    }    
}

int main() {
    int computerNum;
    int connectionCnt;
    int start, dest;

    std::cin >> computerNum >> connectionCnt;
    for (int i = 0; i < connectionCnt; i++) {
        std::cin >> start >> dest;
        connectionList[start].push_back(dest);
        connectionList[dest].push_back(start);
    }

    for (int i = 1; i <= computerNum; i++) {
        std::sort(connectionList[i].begin(), connectionList[i].end());
    }

    solve(1);
    std::cout << infectionCnt << std::endl;

    return 0;
}