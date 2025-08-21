#include <iostream>
#include <algorithm>

using ll = long long;
int N, M;
int A[100001] = {0, };
int B[100001] = {0, };

int APower[100001] = {0, };

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A, A + N);

    ll HI_win = 0;
    ll ARC_win = 0;
    ll draw = 0;
    for (int i = 0; i < M; i++) {
        int lo = std::lower_bound(A, A + N, B[i]) - A;
        int hi = std::upper_bound(A, A + N, B[i]) - A;

        HI_win += N - hi;
        ARC_win += lo;
        draw += hi - lo;
    }
    std::cout << HI_win << " " << ARC_win << " " << draw <<std::endl;
    return 0;
}