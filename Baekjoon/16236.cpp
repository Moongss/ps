#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define NONE 0

int map[20][20] = {0, };
int moveCnt[20][20] = {0, };
bool isVisited[20][20] = {0, };

int N;

int sharkSize = 2;
int sharkEatCnt = 0;
int sum = 0;

std::pair<int, int> currentSharkLocation;

//우선순위(Z): 위, 왼쪽, 오른쪽, 아래
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int abs(int num) {
    return (num < 0) ? -num : num;
}

void updateSharkInfo(std::pair<int, int> newSharkLocation) {
    map[newSharkLocation.first][newSharkLocation.second] = NONE;

    //돌아갈 수 있어서 이렇게 하면 안된다... 배열을 하나 만들어두자.
    // sum += abs(newSharkLocation.first - currentSharkLocation.first);
    // sum += abs(newSharkLocation.second - currentSharkLocation.second);

    sum += moveCnt[newSharkLocation.first][newSharkLocation.second];
    currentSharkLocation = newSharkLocation;

    sharkEatCnt++;
    if (sharkEatCnt == sharkSize) {
        sharkSize++;
        sharkEatCnt = 0;
    }
}

bool isValidCoordinate(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void movePrint() {
    std::cout << "-------MAP-------" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // std::cout << "-------Move-------" << std::endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         std::cout << moveCnt[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

}

struct compare {
    bool operator()(std::pair<std::pair<int, int>, int>a, std::pair<std::pair<int, int>, int>b) {
        if (a.second == b.second) {
            if (a.first.first == b.first.first)
                return a.first.second > b.first.second;
            return a.first.first > b.first.first;
        }
        return a.second > b.second;
    }
};

void solve() {
    //memory가 상관 없을까?
    std::priority_queue<std::pair<std::pair<int, int>, int>, 
        std::vector<std::pair<std::pair<int, int>, int>>, compare>minDistanceQueue;
    std::queue<std::pair<int, int> >coordinateQueue;
    std::pair<int, int> coordinate;
    
    int minDistance = 4242;
    bool isFindTarget = false;

    memset(moveCnt, 0, sizeof(moveCnt));
    memset(isVisited, 0, sizeof(isVisited));

    //이 코드에서는 가장 가까운 "자기보다 작은 물고기"를 찾아야 한다..
    coordinateQueue.push(currentSharkLocation);
    isVisited[currentSharkLocation.first][currentSharkLocation.second] = true;

    while (!coordinateQueue.empty()) {
        coordinate = coordinateQueue.front();
        coordinateQueue.pop();

        int row = coordinate.first;
        int col = coordinate.second;
        
        if (map[row][col] != NONE && map[row][col] < sharkSize &&
            moveCnt[row][col] <= minDistance) {
            // std::cout << "[" << currentSharkLocation.first << "][" << currentSharkLocation.second << "] --> " << "[" << row << "][" << col << "]" << std::endl;

            if (minDistance > moveCnt[row][col])
                minDistance = moveCnt[row][col];
            isFindTarget = true;

            minDistanceQueue.push({{row, col}, minDistance});
            // movePrint();
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = row + dy[i];
            int newCol = col + dx[i];

            if (isValidCoordinate(newRow, newCol) &&
                map[newRow][newCol] <= sharkSize &&
                !isVisited[newRow][newCol]) { 
                moveCnt[newRow][newCol] = moveCnt[row][col] + 1;
                isVisited[newRow][newCol] = true;
                coordinateQueue.push({newRow, newCol});
            }
        }
    }

    if (!isFindTarget) {
        std::cout << sum << std::endl;
        return;
    }
    
    updateSharkInfo(minDistanceQueue.top().first);
    solve();
}

int main() {
    std::cin >> N;

    int info;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 9) {
                currentSharkLocation = {i, j};
                map[i][j] = NONE;
            }
        }
    }

    solve();
    return 0;
}