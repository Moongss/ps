#include <iostream>

int N, newScore, P;
int save[51] = {0, };

int main() {
    std::cin >> N >> newScore >> P;
    for (int i = 1; i <= N; i++) std::cin >> save[i];

    if (N == 0) { std::cout << 1 << std::endl; }
    else if (N == P && save[N] == newScore) { std::cout << -1 << std::endl;}
    else {
        int rank = 1;
        for (int i = 1; i <= N; i++) {
            if (save[i] > newScore) {
                rank++;
            }
            if (save[i] == newScore) {
                rank = rank;
            }
        }
        if (rank <= P)
            std::cout << rank << std::endl;
        else
            std::cout << -1 << std::endl;
    }
    return 0;
}