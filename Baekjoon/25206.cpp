#include <iostream>
#include <string>

int convertGrade(std::string str) {
    if (str == "A+") return 45;
    if (str == "A0") return 40;
    if (str == "B+") return 35;
    if (str == "B0") return 30;
    if (str == "C+") return 25;
    if (str == "C0") return 20;
    if (str == "D+") return 15;
    if (str == "D0") return 10;
    else return 0;
}

int main() {
    std::string str;
    double credit;
    std::string grade;

    double cnt = 0;
    long double sum = 0;
    for (int i = 0; i < 20; i++) {
        std::cin >> str >> credit >> grade;
        std::cin.get();

        if (grade[0] == 'P')
            continue;
        else {
            cnt += credit;
            sum += credit * convertGrade(grade);
        }
    }
    printf("%.6Lf\n", sum / cnt / 10);
    return 0;
}