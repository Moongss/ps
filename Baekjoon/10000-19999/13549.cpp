#include <deque>
#include <iostream>

int solve(int start, int end) {
    std::deque<std::pair<int, int>> location;
    bool visit[100001] = {
        0,
    };

    location.push_back({start, 0});
    while (!location.empty()) {
        int currentLocation = location.front().first;
        int currentTime = location.front().second;
        location.pop_front();
        visit[currentLocation] = true; //key

        if (currentLocation == end) {
            return (currentTime);
        }

        if (currentLocation * 2 <= 100000 && !visit[currentLocation * 2]) {
            location.push_front({currentLocation * 2, currentTime});
        }
        if (currentLocation + 1 <= 100000 && !visit[currentLocation + 1]) {
            location.push_back({currentLocation + 1, currentTime + 1});
        }
        if (currentLocation - 1 >= 0 && !visit[currentLocation - 1]) {
            location.push_back({currentLocation - 1, currentTime + 1});
        }
    } 
    return (0);
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::cout << solve(N, K) << std::endl;
    return 0;
}