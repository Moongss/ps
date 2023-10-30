#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
ll X, Y, D, T;
ld getMinTime(ld L) {
    ld C = 0;
    ld result = max((ld)2.0, ceil(L / D)) * T;
    while (L >= D) {
        L -= D;
        C += T;
    }
    // printf("L : %Lf\n", L);
    // printf("C : %Lf\n", C);
    // printf("C + 2 * T : %Lf\n", C + 2 * T);
    // printf("C + L : %Lf\n", C + L);

    result = min(result, min(C + T + (D - L), C + L));
    //D <= L < 2D
    // printf("C + T + (L - D) : %Lf\n", C + T + (L - D));
    // result = min(result, C + T + (L - D));

    // while (L > 0) {
    //     C = C + T; // 4 + 2 = 6
    //     L = L - D; // 4 - 3 = 1
    //     if (0 < L && L < D) {
    //         result = min(result, C + L);
    //     }
    //     if (L < 0) {
    //         result = min(result, C - L);
    //     }
    // }
    return result;
}
int main() {
    fastio;
    cin >> X >> Y >> D >> T;

    ld L = sqrt(X * X + Y * Y);
    if (T >= D)
        printf("%.11Lf\n", L);
    else {
        printf("%.11Lf\n", getMinTime(L));
    }
    return 0;
}