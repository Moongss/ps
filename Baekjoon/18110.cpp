#include <iostream>

int N;
int difficulty[31] = {0, };
int TM;
int opinion;

int main() {
    std::cin >> N;

    TM = (int)(N * 0.15f + 0.5f);
    for (int i = 0; i < N; i++) {
        std::cin >> opinion;
        difficulty[opinion]++;
    }

    int lower_TM = TM;
    int upper_TM = TM;

    int opinionIndex = 1;
    while (lower_TM) {
        if (difficulty[opinionIndex]) {
            difficulty[opinionIndex]--;
            lower_TM--;
        } else {
            opinionIndex++;
        }
    }

    opinionIndex = 30;
    while (upper_TM) {
        if (difficulty[opinionIndex]) {
            difficulty[opinionIndex]--;
            upper_TM--;
        } else {
            opinionIndex--;
        }
    }

    int sum = 0;
    for (int i = 1; i <= 30; i++) {
        sum += difficulty[i] * i;
    }

    if (N != 0)
        std::cout << (int)((float)sum / (N - TM * 2) + 0.5f)<< std::endl;
    else
        std::cout << 0 << std::endl;
    return 0;
}