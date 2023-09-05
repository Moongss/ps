#include <iostream>
#include <queue>
#include <string.h>

#define WALL -1
#define TOMATO_NOT_RIPE 0
#define TOMATO_RIPED 1

int M, N;
int box[1002][1002];
int ripedDay[1002][1002] = {0, };
std::queue<std::pair<int, int> >tomatoLocations;

void addLocations(int y, int x) {
    tomatoLocations.push(std::make_pair(y, x + 1));
    tomatoLocations.push(std::make_pair(y, x - 1));
    tomatoLocations.push(std::make_pair(y + 1, x));
    tomatoLocations.push(std::make_pair(y - 1, x));
}

void showRipedDay() {
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            std::cout << ripedDay[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void showbox() {
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            std::cout << box[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int getMaxRipedDay() {
    int max = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            max = (ripedDay[i][j] > max) ? ripedDay[i][j] : max;
        }
    }

    return max;
}

void solve() {
    
    std::pair<int, int> location;
    int x, y;

    while (!tomatoLocations.empty()) {
        // showbox();
        // showRipedDay();
        location = tomatoLocations.front();
        tomatoLocations.pop();

        
        y = location.first;
        x = location.second;
        
        // std::cout << "current y : " << y << ", x : " << x << std::endl;

        if (box[y][x] != TOMATO_RIPED) {
            continue;
        }

        if (box[y][x + 1] == TOMATO_NOT_RIPE || box[y][x - 1] == TOMATO_NOT_RIPE ||
            box[y + 1][x] == TOMATO_NOT_RIPE || box[y - 1][x] == TOMATO_NOT_RIPE) {
            if (box[y][x + 1] == TOMATO_NOT_RIPE) {
                box[y][x + 1] = TOMATO_RIPED;
                ripedDay[y][x + 1] = ripedDay[y][x] + 1;
            }
            if (box[y][x - 1] == TOMATO_NOT_RIPE) {
                box[y][x - 1] = TOMATO_RIPED;
                ripedDay[y][x - 1] = ripedDay[y][x] + 1;
            }
            if (box[y + 1][x] == TOMATO_NOT_RIPE) {
                box[y + 1][x] = TOMATO_RIPED;
                ripedDay[y + 1][x] = ripedDay[y][x] + 1;
            }
            if (box[y - 1][x] == TOMATO_NOT_RIPE) {
                box[y - 1][x] = TOMATO_RIPED;
                ripedDay[y - 1][x] = ripedDay[y][x] + 1;
            }
            addLocations(y, x);
        }
    }
}

bool checkBox() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (box[i][j] == TOMATO_NOT_RIPE) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int tomatoInfo;

    memset(box, -1, sizeof(box));  
    std::cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> tomatoInfo;
            box[i][j] = tomatoInfo;
            if (tomatoInfo == TOMATO_RIPED) {
                tomatoLocations.push(std::make_pair(i, j));
                ripedDay[i][j] = 0;
            }
        }
    }

    solve();

    if (checkBox())
        std::cout << getMaxRipedDay() << std::endl;
    else
        std::cout << -1 << std::endl;

    return 0;
}