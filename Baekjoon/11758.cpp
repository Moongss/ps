#include <iostream>
#include <algorithm>

struct point{int x; int y;};
point p1, p2, p3;

int ccw(point p1, point p2, point p3) {
    return ((p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - 
            (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y));
}

int main() {
    std::cin >> p1.x >> p1.y;   
    std::cin >> p2.x >> p2.y;   
    std::cin >> p3.x >> p3.y;   

    int result = ccw(p1, p2, p3);
    if (result > 0)
        std::cout << 1 << std::endl;
    else if (result == 0)
        std::cout << 0 << std::endl;
    else
        std::cout << -1 << std::endl;

    return 0;
}