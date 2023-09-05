#include <iostream>

void solve(int x, int y, int n) {
    // y to x

    int result[1001] = {0, };
    int tmp = 0;
    int next = y - tmp;

    result[x] = x;
    result[y] = y;
    while (n > 1) {
        if (next >= x) {
            y = next;
            result[y] = y;
        }
        else {
            break;
        }
        n--;
        tmp++;
        next = y - tmp;
    }

    if (n == 1 && next >= x) {
         n--;
    }
    
    if (n == 0)
       for (int i = 1; i <= 1000; i++) {
            if (result[i] != 0)
                std::cout << i << " ";
        } 
    else {
        std::cout << -1;
    }
    std::cout << std::endl;
}
int main() {
    int x, y, t, n;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> x >> y >> n;
        solve(x, y, n);
    }
}
