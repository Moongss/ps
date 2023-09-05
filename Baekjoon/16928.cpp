#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

std::pair<int, int> currentPair;
std::vector<std::pair<int, int> >::iterator iter;
std::vector<std::pair<int, int> > snakeList; //src, dest
std::vector<std::pair<int, int> > ladderList; //same
bool isVisited[106] = {false, };

#define START_POINT 1
#define END_POINT 100

void solve() {
    std::queue<std::pair<int, int> >locationQueue; //location, cnt
    locationQueue.push({START_POINT, 0});
    while (!locationQueue.empty()) {
        currentPair = locationQueue.front();
        locationQueue.pop();
        
        if (currentPair.first == END_POINT) 
            break;

        //ladder check
        for (iter = ladderList.begin(); iter != ladderList.end(); iter++) {
            if (currentPair.first == iter->first)
                currentPair.first = iter->second;
        }
        //snake check
        for (iter = snakeList.begin(); iter != snakeList.end(); iter++) {
            if (currentPair.first == iter->first)
                currentPair.first = iter->second;
        }

        //visited check
        for (int i = 1; i <= 6; i++) {
            if (!isVisited[currentPair.first + i]) {
                isVisited[currentPair.first + i] = true;
                locationQueue.push({currentPair.first + i, currentPair.second + 1});
            }
        }
    }

    std::cout << currentPair.second << std::endl;
}


int main() {
    int src, dest;
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> src >> dest;
        ladderList.push_back({src, dest});
    }
    for (int i = 0; i < M; i++) {
        std::cin >> src >> dest;
        snakeList.push_back({src, dest});
    }
    solve();

    return 0;
}