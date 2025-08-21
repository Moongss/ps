#include <iostream>

typedef struct Point{
    long x;
    long y;
};

typedef struct Line {
    Point p1;
    Point p2;
};

Line L1, L2;

int ccw(Point a, Point b, Point c) {

    long result = (a.x * b.y + b.x * c.y + c.x * a.y) - 
                 (b.x * a.y + c.x * b.y + a.x * c.y);
    
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    return 0;
}

int main() {
    std::cin >> L1.p1.x >> L1.p1.y >> L1.p2.x >> L1.p2.y;
    std::cin >> L2.p1.x >> L2.p1.y >> L2.p2.x >> L2.p2.y;

    int L1L2 = ccw(L1.p1, L1.p2, L2.p1) * ccw(L1.p1, L1.p2, L2.p2);
    int L2L1 = ccw(L2.p1, L2.p2, L1.p1) * ccw(L2.p1, L2.p2, L1.p2);

    if (L1L2 == 0 && L2L1 == 0) {
        int L1_min_x = std::min(L1.p1.x, L1.p2.x);
        int L1_max_x = std::max(L1.p1.x, L1.p2.x);
        int L1_min_y = std::min(L1.p1.y, L1.p2.y);
        int L1_max_y = std::max(L1.p1.y, L1.p2.y);
        int L2_min_x = std::min(L2.p1.x, L2.p2.x);
        int L2_min_y = std::min(L2.p1.y, L2.p2.y);
        int L2_max_x = std::max(L2.p1.x, L2.p2.x);
        int L2_max_y = std::max(L2.p1.y, L2.p2.y);

        if ((L1_min_x <= L2_max_x && L2_min_x <= L1_max_x) &&
            (L1_min_y <= L2_max_y && L2_min_y <= L1_max_y))
            std::cout << 1 << std::endl;
        else
            std::cout << 0 << std::endl;
    } else if (L1L2 <= 0 && L2L1 <= 0) { // {0, -1}, {-1, 0}, {-1, -1}
        std::cout << 1 << std::endl;
    } else { //하나라도 1이면 교차x
        std::cout << 0 << std::endl;
    }
    return 0;
}