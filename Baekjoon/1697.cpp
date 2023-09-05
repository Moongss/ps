#include <iostream>
#include <queue>

bool isVisited[100001] = {false, };
std::vector<int> point[100001];

int solve(int N, int K) {
    int tmp;
    int currentLevelSize;
    int cnt = 0;
    std::queue<int> save;

    save.push(N);
    isVisited[N] = true;

    if (N == K)
        return 0;
    while (!save.empty()) {
        currentLevelSize = save.size();
        for (int k = 0; k < currentLevelSize; k++) {
            tmp = save.front();
            save.pop();
            for (int i = 0; i < point[tmp].size(); i++) {
                int currentPoint = point[tmp][i];
                if (currentPoint == K)
                    return cnt + 1;
                if (!isVisited[currentPoint]) {
                    isVisited[currentPoint] = true;
                    save.push(currentPoint);
                }
            }
        }
        cnt++;
    }
    return -42;
}

int main() {
    int N, K;
    
    std::cin >> N >> K;

    for (int i = 0; i <= 100000; i++) {
        if (i > 0)
            point[i].push_back(i - 1); 
        if (i < 100000)
            point[i].push_back(i + 1);
        if (i * 2 <= 100000)
            point[i].push_back(i * 2);
    }

    std::cout << solve(N, K) << std::endl;
    return 0;
}