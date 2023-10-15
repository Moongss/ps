#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];
int n;

int getCnt(int start1, int end1, int start2, int end2) {
    int cnt = 0;
    for (int i = start1; i <= end1; i++) {
        for (int j = start2; j <= end2; j++) {
            if (arr[i][j] != arr[n - i + 1][j])
                cnt++;
            if (arr[i][j] != arr[i][n - j + 1])
                cnt++;
            if (arr[i][j] != arr[n - i + 1][n - j + 1])
                cnt++;
        }
    }
    std::cout << cnt << std::endl;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cin >> arr[i][j];
            }
        }

        int min = 42424242;
        min = std::min(min, getCnt(1, n / 2, 1, n / 2));
        min = std::min(min, getCnt(1, n / 2, n / 2 + 1, n));
        min = std::min(min, getCnt(n / 2 + 1, n, 1, n / 2));
        min = std::min(min, getCnt(n / 2 + 1, n, n / 2 + 1, n));
        std::cout << min << std::endl;
    }
    return 0;
}