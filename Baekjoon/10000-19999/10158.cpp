#include <iostream>

struct Point{
    int x;
    int y;
};

int main() {
    int w, h;
    Point cur;
    int move;

    std::cin >> w >> h >> cur.x >> cur.y >> move;

    int xMove = cur.x + move;
    int yMove = cur.y + move;

    if ((xMove / w) % 2 == 0) {
        std::cout << (xMove % w);
    } else {
        std::cout << w - (xMove % w);
    }

    std::cout << " ";
    if ((yMove / h) % 2 == 0) {
        std::cout << (yMove % h);
    } else {
        std::cout << h - (yMove % h);
    }

    return 0;
}