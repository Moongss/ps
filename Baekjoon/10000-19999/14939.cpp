#include <iostream>
#include <string>

bool flag[10];
bool isImpossible = true;
char tmp[10][10];
char arr[10][10];

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

int result = 424242;
int cnt = 0;

void push_switch(int x, int y) {
    cnt++;
    for (int i = 0; i < 5; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX < 0 || newX > 9 || newY < 0 || newY > 9)
            continue;

        if (tmp[newX][newY] == 'O') {
            tmp[newX][newY] = '#';
        } else {
            tmp[newX][newY] = 'O';
        }
    }
}

void init(int bits) {
    cnt = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tmp[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < 10; i++) {
        flag[i] = false;
        if (bits & (1 << i))
            flag[i] = true;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cin >> arr[i][j];
        }
    }

    int bits = 0;
    while (bits < 1024) { // (0000000000) 0 ~ 2^10 - 1 (1111111111)
        init(bits);

        for (int i = 0; i < 10; i++) {
            if (flag[i])
                push_switch(0, i);
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                if (tmp[i][j] == 'O') {
                    push_switch(i + 1, j);
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            if (tmp[9][i] == 'O') {
                cnt = -1;
            }
        }
        if (cnt != -1)
            result = std::min(result, cnt);
        bits++;
    }

    if (result == 424242)
        std::cout << -1 << std::endl;
    else
        std::cout << result << std::endl;
    return 0;
}