#include <iostream>
#include <vector>
#include <algorithm>

class Point {
    public:
        int x;
        int y;

        Point(int x, int y): x(x), y(y) {}
        virtual ~Point() {}
};

bool compare(Point &a, Point &b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    int N, x, y;
    std::vector<Point> pointList;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        pointList.push_back(Point(x, y));
    }

    // TEST
    // for (std::vector<Point>::iterator it = pointList.begin(); it != pointList.end(); it++) {
    //     std::cout << (*it).x << " " << (*it).y << std::endl;
    // }

    std::sort(pointList.begin(), pointList.end(), compare);
    for (std::vector<Point>::iterator it = pointList.begin(); it != pointList.end(); it++) {
        std::cout << (*it).x << " " << (*it).y << "\n";
    }
    return 0;
}