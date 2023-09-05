#include <iostream>

std::pair<long, long> s1_x, s1_y, s2_x, s2_y;

long gcd(long a, long b){
    long tmp, n;
 
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    long x, y;
    long minX = 424242, maxX = -424242;
    long minY = 424242, maxY = -424242;
    for (int i = 0; i< 4; i++) {
        std::cin >> x >> y;
        if (minX > x) minX = x;
        if (minY > y) minY = y;
        if (maxX < x) maxX = x;
        if (maxY < y) maxY = y;
    }

    s1_x = {minX, maxX};
    s1_y = {minY, maxY};
    // std::cout << "s1_x : " << s1_x.first << "s1_x : " << s1_x.second << std::endl;
    // std::cout << "s1_y : " << s1_y.first << "s1_y : " << s1_y.second << std::endl;

    minX = minY = 424242;
    maxX = maxY = -424242;

    for (int i = 0; i < 4; i++) {
        std::cin >> x >> y;
        if (minX > x) minX = x;
        if (minY > y) minY = y;
        if (maxX < x) maxX = x;
        if (maxY < y) maxY = y;
    }

    s2_x = {minX, maxX};
    s2_y = {minY, maxY};

    // std::cout << "s2_x : " << s2_x.first << "s2_x : " << s2_x.second << std::endl;
    // std::cout << "s2_y : " << s2_y.first << "s2_y : " << s2_y.second << std::endl;
    long focus_s1_x = (s1_x.second + s1_x.first); // /2 안 한거임.
    long focus_s1_y = (s1_y.second + s1_y.first);
    long focus_s2_x = (s2_x.second + s2_x.first);
    long focus_s2_y = (s2_y.second + s2_y.first);
    
    
    long y2y1 = focus_s2_y - focus_s1_y;
    long x2x1 = focus_s2_x - focus_s1_x;

    // std::cout << "y2y1 : " << y2y1 << std::endl;
    // std::cout << "x2x1 : " << x2x1 << std::endl;
    //p
    if (y2y1 % x2x1 != 0) {
       long k = gcd(y2y1, x2x1);

       if (k < 0) k *= -1;
       if (x2x1 < 0) {y2y1 *= -1; x2x1 *= -1;}
        std::cout << y2y1 / k << "/" << x2x1 /k << " "; // 기약분수 해야됨

    }
    else {
       if (x2x1 < 0) {y2y1 *= -1; x2x1 *= -1;}
        std::cout << y2y1/x2x1 << " ";
    }

    //q
    long tmp = -y2y1 * focus_s1_x + focus_s1_y * x2x1;
    if (tmp % (x2x1*2) != 0) {
        long k = gcd(tmp, x2x1*2);

       if (k < 0) k *= -1;
       if (x2x1 < 0) {tmp *= -1; x2x1 *= -1;}
        std::cout << tmp / k << "/" << (x2x1*2) / k << std::endl;
    }
    else {
       if (x2x1 < 0) {tmp *= -1; x2x1 *= -1;}
        std::cout << tmp/(x2x1*2) << std::endl;
    }
    // - y2y1 * focus_s1_x / x2x1 + focus_s1_y;

    return 0;
}