#include <iostream>
#include <vector>
#include <algorithm>

#define HOME 1
#define CHICKEN 2
#define CHICKEN_MAX 13

std::vector<std::pair<int, int> >homeList;
std::vector<std::pair<int, int> >chickenList;
std::pair<int, int>coordinate;

int N, M;
int result = 42424242;
std::pair<int, int>tmpLocationArr[CHICKEN_MAX];

int calculateDistance(int x, int y) {
    if (x > y)
        return x - y;
    return y - x;
}

int getMinimumDistanceByPerCase(int n) {
    std::vector<std::pair<int, int> >::iterator homeIterator;
    std::pair<int, int> chickenLocation;
    int result = 0;

    for (homeIterator = homeList.begin(); homeIterator != homeList.end(); homeIterator++) {
        int minDistancePerHome = 424242;
        for (int i = 0; i < n; i++) {
            int totalDistance = 0;
            chickenLocation = tmpLocationArr[i];
            totalDistance += calculateDistance(chickenLocation.first, homeIterator->first);
            totalDistance += calculateDistance(chickenLocation.second, homeIterator->second);
            if (minDistancePerHome > totalDistance)
                minDistancePerHome = totalDistance;
        }
        result += minDistancePerHome;
    }

    return result;
}


void solve(int range, int cnt, int start, int current) {

    if (current == cnt) {
        int distance = getMinimumDistanceByPerCase(cnt);
        if (result > distance) result = distance;
        return;
    }

    for (int i = start; i < range; i++) {
        tmpLocationArr[current] = chickenList[i];
        solve(range, cnt, i + 1, current + 1);
    }
}

int main() {
    int info;

    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> info;
            coordinate = {i, j};
            if (info == HOME) homeList.push_back(coordinate);
            if (info == CHICKEN) chickenList.push_back(coordinate);
        }
    }

    //13 c 6 -> 최대인데.. 조합을 구해서, 매 조합별로 구하는걸 체크.
    //M <= chieckenNum < 13 (chickenList.size())
    solve(chickenList.size(), M, 0, 0);
    std::cout << result << std::endl;
    return 0;
}