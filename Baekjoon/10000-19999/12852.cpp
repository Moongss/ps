#include <iostream>
#include <queue>

#define MAX 10000000

int save[10000001] = {0, };
int N;

void solve() {
    std::queue<int> q;

    q.push(1);
    while (!q.empty()) {
        int elem = q.front();
        q.pop();

        if (elem == N)
            break;
        if (elem * 3 < MAX && !save[elem * 3]) {
            save[elem * 3] = elem;
            q.push(elem * 3);
        }
        if (elem * 2 < MAX && !save[elem * 2]) {
            save[elem * 2] = elem;
            q.push(elem * 2);
        }
        if (elem + 1 < MAX && !save[elem + 1]) {
            save[elem + 1] = elem;
            q.push(elem + 1);
        }
    }

    int tmp = save[N];
    int cnt = 0;
    while (tmp != 0) {
        tmp = save[tmp];
        cnt++;
    }

    std::cout << cnt << "\n";
    std::cout << N << " ";
    tmp = save[N];
    while (tmp != 0) {
        std::cout << tmp;
        if (tmp != 1) {
            std::cout << " ";
        }
        tmp = save[tmp];
    }
    std::cout << "\n";
}

int main() {
    std::cin >> N;
    solve();
    return 0;
}