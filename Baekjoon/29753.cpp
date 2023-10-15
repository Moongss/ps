#include <iostream>

int N;
double X;

int getScore(std::string str) {
    if (str == "A+") return 450;
    if (str == "A0") return 400;
    if (str == "B+") return 350;
    if (str == "B0") return 300;
    if (str == "C+") return 250;
    if (str == "C0") return 200;
    if (str == "D+") return 150;
    if (str == "D0") return 100;
    return 0;
}

std::string getScore2(double d) {
    std::cout << "d : " << d << std::endl;
    if (d == 0.0) return "F";
    else if (d <= 1.0) return "D0";
    else if (d <= 1.5) return "D+";
    else if (d <= 2.0) return "C0";
    else if (d <= 2.5) return "C+";
    else if (d <= 3.0) return "B0";
    else if (d <= 3.5) return "B+";
    else if (d <= 4.0) return "A0";
    else return "A+";
}

int main() {
    std::cin >> N >> X;

    int x100 = X * 100;
    int sum = 0;
    int tmp = 0;
    for (int i = 0; i < N - 1; i++) {
        int c;
        std::string g;

        std::cin >> c >> g;

        tmp += c * getScore(g);
        sum += c;
        std::cout << tmp << std::endl;
    }

    int c;
    std::cin >> c;
    sum += c;
    sum = (X * 100) * sum;
    std::cout << "sum : " << sum << std::endl;
    std::cout << sum - tmp << std::endl;
    
    if ((double)(sum - tmp) / (c) > 450)
        std::cout << "impossible\n";
    else {
        std::cout << getScore2((double)(sum - tmp) / (c * 100)) << std::endl;
    }

    return 0;
}