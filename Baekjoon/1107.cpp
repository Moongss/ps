#include <iostream>

#define CHANNEL_MAX 500000
bool wrongNumArr[10] = {0, };

bool hasWrongNumber(int channel) {
    if (channel == 0 && wrongNumArr[0])
        return true;

    while (channel != 0) {
        int num = channel % 10;
        channel /= 10;
        if (wrongNumArr[num])
            return true;
    }
    return false;
}

int getNumLength(int channel) {
    if (channel < 10)
        return 1;

    int length = 0;
    while (channel != 0) {
        channel /= 10;
        length++;
    }    
    return length;
}

int main() {
    int targetChannel;
    int wrongNum;
    int M;

    std::cin >> targetChannel;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> wrongNum;
        wrongNumArr[wrongNum] = true;
    }

    int min = 10000000;
    int numLength, numDistance;

    if (targetChannel == 100) {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (M == 10) {
        numDistance = (100 > targetChannel) ? 100 - targetChannel : targetChannel - 100;
        std::cout << numDistance << std::endl;
        return 0;
    }

    for (int i = 0; i <= 1000000; i++) {
        if (!hasWrongNumber(i) || i == 100) {
            numLength = (i != 100) ? getNumLength(i) : 0;
            numDistance = (i > targetChannel) ? i - targetChannel : targetChannel - i;

            if (min >= numLength + numDistance)
                min = numLength + numDistance;
        }
    }
    std::cout << min << std::endl;
    return 0;
}