#include <iostream>

long P[51] = {0, };
long B[51] = {0, };
long Burger[51] = {0, };

long result = 0;
long solve(int N, long X) {
    long highBun = 1;
    long midPetty = 1 + Burger[N - 1] + 1;
    long lowBun = Burger[N];

    if (N == 0)
        return 1;
    if (X <= highBun) {
        return 0;
    } else if (X < midPetty) {
        return solve(N - 1, X - 1);
    } else if (X == midPetty) {
        return P[N - 1] + 1;
    } else if (X < lowBun) {
        return P[N - 1] + 1 + solve(N - 1, X - midPetty);
    } else {
        return P[N - 1] * 2 + 1;
    }
}

int main() {
    long N, X;
    std::cin >> N >> X;

    P[0] = 1;
    B[0] = 0;
    Burger[0] = 1;
    for (int i = 1; i <= 50; i++) {
        P[i] = P[i - 1] * 2 + 1;
        B[i] = B[i - 1] * 2 + 2;
        Burger[i] = P[i] + B[i];
    } 
    
    std::cout << solve(N, X) << std::endl;
    return 0; 
}