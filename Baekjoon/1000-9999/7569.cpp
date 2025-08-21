#include <iostream>
#include <queue>
#include <string.h>

#define WALL -1
#define TOMATO_NOT_RIPE 0
#define TOMATO_RIPED 1

int M, N, H;
int box[102][102][102];
int ripedDay[102][102][102] = {0, };
std::queue<std::pair<int, std::pair<int, int> > >tomatoLocations;

void addLocations(int z, int y, int x) {
    tomatoLocations.push(std::make_pair(z + 1, std::make_pair(y, x)));
    tomatoLocations.push(std::make_pair(z - 1, std::make_pair(y, x)));
    tomatoLocations.push(std::make_pair(z, std::make_pair(y, x + 1)));
    tomatoLocations.push(std::make_pair(z, std::make_pair(y, x - 1)));
    tomatoLocations.push(std::make_pair(z, std::make_pair(y + 1, x)));
    tomatoLocations.push(std::make_pair(z, std::make_pair(y - 1, x)));

}

void showRipedDay() {
    for (int k = 0; k <= H + 1; k++) {
        for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j <= M + 1; j++) {
                std::cout << ripedDay[k][i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }


}

void showbox() {
    for (int k = 1; k <= H; k++) {
        std::cout << "level : " << k << std::endl;
        for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j <= M + 1; j++) {
                std::cout << box[k][i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int getMaxRipedDay() {
    int max = -1;

    for (int k = 1; k <= H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                max = (ripedDay[k][i][j] > max) ? ripedDay[k][i][j] : max;
            }
        }
    }


    return max;
}

void solve() {
    
    std::pair<int, int> location;
    int x, y, z;

    while (!tomatoLocations.empty()) {
        // showbox();
        // showRipedDay();
        location = tomatoLocations.front().second;

        z = tomatoLocations.front().first;
        y = location.first;
        x = location.second;
        
        tomatoLocations.pop();
        // std::cout << "current y : " << y << ", x : " << x << std::endl;

        if (box[z][y][x] != TOMATO_RIPED) {
            continue;
        }

        if (box[z][y][x + 1] == TOMATO_NOT_RIPE || box[z][y][x - 1] == TOMATO_NOT_RIPE ||
            box[z][y + 1][x] == TOMATO_NOT_RIPE || box[z][y - 1][x] == TOMATO_NOT_RIPE ||
            box[z + 1][y][x] == TOMATO_NOT_RIPE || box[z - 1][y][x] == TOMATO_NOT_RIPE) {
            if (box[z][y][x + 1] == TOMATO_NOT_RIPE) {
                box[z][y][x + 1] = TOMATO_RIPED;
                ripedDay[z][y][x + 1] = ripedDay[z][y][x] + 1;
            }
            if (box[z][y][x - 1] == TOMATO_NOT_RIPE) {
                box[z][y][x - 1] = TOMATO_RIPED;
                ripedDay[z][y][x - 1] = ripedDay[z][y][x] + 1;
            }
            if (box[z][y + 1][x] == TOMATO_NOT_RIPE) {
                box[z][y + 1][x] = TOMATO_RIPED;
                ripedDay[z][y + 1][x] = ripedDay[z][y][x] + 1;
            }
            if (box[z][y - 1][x] == TOMATO_NOT_RIPE) {
                box[z][y - 1][x] = TOMATO_RIPED;
                ripedDay[z][y - 1][x] = ripedDay[z][y][x] + 1;
            }
            if (box[z + 1][y][x] == TOMATO_NOT_RIPE) {
                box[z + 1][y][x] = TOMATO_RIPED;
                ripedDay[z + 1][y][x] = ripedDay[z][y][x] + 1;
            }
            if (box[z - 1][y][x] == TOMATO_NOT_RIPE) {
                box[z - 1][y][x] = TOMATO_RIPED;
                ripedDay[z - 1][y][x] = ripedDay[z][y][x] + 1;
            }
            addLocations(z, y, x);
        }
    }
}

bool checkBox() {
    for (int k = 1; k <= H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (box[k][i][j] == TOMATO_NOT_RIPE) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int tomatoInfo;

    memset(box, -1, sizeof(box));  
    std::cin >> M >> N >> H;
    for (int k = 1; k <= H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                std::cin >> tomatoInfo;
                box[k][i][j] = tomatoInfo;
                if (tomatoInfo == TOMATO_RIPED) {
                    tomatoLocations.push(std::make_pair(k, std::make_pair(i, j)));
                    ripedDay[k][i][j] = 0;
                }
            }
        }
    }

    // showbox();
    // showRipedDay();
    solve();

    if (checkBox())
        std::cout << getMaxRipedDay() << std::endl;
    else
        std::cout << -1 << std::endl;

    return 0;
}