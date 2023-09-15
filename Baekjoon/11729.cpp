#include <iostream>

int N;

int getMoveCnt(int N) {
    int result = 1;
    while (N--) {
        result *= 2;
    }
    return result - 1;
}

void solve(int cur, int from, int to) {
    if (cur == N) {
        std::cout << from << " " << to << "\n";
    } else {
        int next = 6 - (from + to);

        solve(cur + 1, from, next);
        std::cout << from << " " << to << "\n";
        solve(cur + 1, next, to);
    }
}

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> N;
    std::cout << getMoveCnt(N) << std::endl;
    solve(1, 1, 3);

    return 0;
}