#include <iostream>

int N;
int question;
struct t_result{int strike; int ball;};

int strike;
int ball;

bool number[1000] = {false, }; // 123 ~ 987;

t_result compare_num(int a, int b) {

    t_result result = {0, 0};

    int digit[10] = {0, };
    for (int i = 0; i < 3; i++) {
        int digitA = a%10;
        int digitB = b%10;

        if (digitA == digitB) {
            result.strike++;
        } else {
            digit[digitA]++;
            digit[digitB]++;
        }

        if (digit[digitA] == 2) result.ball++;
        if (digit[digitB] == 2) result.ball++;

        a/=10;
        b/=10;
    }

    return result;
}

int main() {
    std::cin >> N;

    for (int i = 123; i <= 987; i++) {
        int hundred = i / 100;
        int ten = i % 100 / 10;
        int one = i % 10;

        if (hundred == 0 || ten == 0 || one == 0 ||
            hundred == ten || hundred == one || ten == one)
            continue;
        
        number[i] = true;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> question >> strike >> ball;

        if (strike == 3) {
            std::cout << "1" << std::endl;
            return 0;
        }
        for (int i = 123; i <= 987; i++) {
            if (number[i] == true) {
                t_result tmp = compare_num(question, i);
                if (tmp.strike != strike || tmp.ball != ball)
                    number[i] = false;
            }
        }
    }

    int result = 0;
    for (int i = 123; i <= 987; i++) {
        if (number[i])
            result++;
    }
    std::cout << result << std::endl;
    return 0;
}