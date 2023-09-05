#include <iostream>
#include <queue>

bool isVisited[100001] = {0, };

std::pair<int, int> solve(int start, int end) {
    int minCnt = 0;
    int minTime = 999999;
    std::queue<std::pair<int, int> > locationQueue; //element, time

    locationQueue.push({start, 0});

    while (!locationQueue.empty()) {
        int currentElement = locationQueue.front().first;
        int currentTime = locationQueue.front().second;
        locationQueue.pop();

        if (currentElement == end && !isVisited[currentElement]) {
            isVisited[currentElement] = true;
            minCnt++;
            minTime = currentTime;
        }
        else {
            if (currentElement == end && minTime == currentTime && isVisited[currentElement]) {
                minCnt++;
                continue;
            }

            isVisited[currentElement] = true; //viuit 시점 차이
            if (currentElement + 1 <= 100000 && !isVisited[currentElement + 1]) {
                locationQueue.push({currentElement + 1, currentTime + 1});
            }
            
            if (currentElement - 1 >= 0 && !isVisited[currentElement - 1]) {
                locationQueue.push({currentElement - 1, currentTime + 1});
            }

            if (currentElement * 2 <= 100000 && !isVisited[currentElement * 2]) {
                locationQueue.push({currentElement * 2, currentTime + 1});
            }
        }
    }
    return {minTime, minCnt};
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::pair<int, int> result = solve(N, K);
    std::cout << result.first << "\n" << result.second << "\n";
    return 0;
}