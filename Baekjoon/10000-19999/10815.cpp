#include <iostream>
#include <set>

int N, M;
std::set<int> s;

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; std::cin >> tmp;
        s.insert(tmp);
    }

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp; std::cin >> tmp;
        if (s.find(tmp) != s.end())
            std::cout << "1 ";
        else
            std::cout << "0 ";
    }
    std::cout << "\n";
    return 0;
}