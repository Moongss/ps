#include <iostream>
#include <string>

#define MODE_NUMERIC 1 << 0
#define MODE_ALPHA_NUMERIC 1 << 1
#define MODE_8_BIT_BYTE 1 << 2
#define MODE_KANJI 1 << 3
#define MODE_TERMINATION 0

std::string ALPHA_NUMERIC_STR = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
int P;
std::string encodeStr;
std::string decodeStr;
std::string result;

int getDecimal(std::string bitString) {
    int cur = 1;
    int sum = 0;
    for (int i = bitString.length() - 1; i >= 0; i--) {
        if (bitString[i] == '1')
            sum += cur;
        cur *= 2;
    }
    return sum;
}

void decode(std::string target) {
    decodeStr = "";
    for (int i = 0; i < target.length(); i++) {
        int dec = 0;
        if (isalpha(target[i]))
            dec = target[i] - 'A' + 10;
        else
            dec = target[i] - '0';

        int divisor = 8;
        while (divisor > 0) {
            if (dec / divisor)
                decodeStr += '1';
            else
                decodeStr += '0';
            dec %= divisor;
            divisor /= 2;
        }
    }
}

int getCountBits(std::string str, int mode, int idx) {
    int result = 0;
    int cur = 1;

    if (mode == MODE_NUMERIC) {
        std::string tmp = str.substr(idx, 10);
        for (int i = 9; i >= 0; i--) {
            if (tmp[i] == '1')
                result += cur;
            cur *= 2;
        }
    } else if (mode == MODE_ALPHA_NUMERIC) {
        std::string tmp = str.substr(idx, 9);
        for (int i = 8; i >= 0; i--) {
            if (tmp[i] == '1')
                result += cur;
            cur *= 2;
        }
    } else if (mode == MODE_8_BIT_BYTE || mode == MODE_KANJI) {
        std::string tmp = str.substr(idx, 8);
        for (int i = 7; i >= 0; i--) {
            if (tmp[i] == '1')
                result += cur;
            cur *= 2;
        }
    } else {
        return 0;
    }
    return result;
}

int main() {
    std::cin >> P;
    std::cin.ignore();

    while (P--) {
        getline(std::cin, encodeStr, '\n');
        decode(encodeStr);

        result = "";
        size_t idx = 0;
        int len = 0;
        while (idx < 152) {
            // WA: 터미네이션 코드로 데이터는 종료되며 만일 데이터 코드를 저장할 공간이 없다면 터미네이션 코드는 생략되거나 불완전한 형태일 수도 있다.
            if (idx + 4 >= 152)
                break;
            std::string modeBits = decodeStr.substr(idx, 4);
            idx += 4;

            int countBits;
            int sum = 0;
            if (modeBits[3] == '1') { 
                countBits = getCountBits(decodeStr, MODE_NUMERIC, idx);
                len += countBits;
                idx += 10;

                std::string numericString;
                while (countBits >= 3) {
                    numericString = decodeStr.substr(idx, 10);
                    idx += 10;

                    sum = getDecimal(numericString);
                    result += (sum / 100) + '0';
                    result += ((sum % 100) / 10) + '0';
                    result += (sum % 10) + '0';
                    countBits -= 3;
                }
                if (countBits == 2) {
                    numericString = decodeStr.substr(idx, 7);
                    idx += 7;

                    sum = getDecimal(numericString);
                    result += (sum / 10) + '0';
                    result += (sum % 10) + '0';
                }
                if (countBits == 1) {
                    numericString = decodeStr.substr(idx, 4);
                    idx += 4;

                    sum = getDecimal(numericString);
                    result += (sum % 10) + '0';
                }
            } else if (modeBits[2] == '1') {
                countBits = getCountBits(decodeStr, MODE_ALPHA_NUMERIC, idx);
                len += countBits;
                idx += 9;

                std::string alphaNumericString;
                while (countBits >= 2) {
                    alphaNumericString = decodeStr.substr(idx, 11);
                    idx += 11;

                    sum = getDecimal(alphaNumericString);
                    result += ALPHA_NUMERIC_STR[sum / 45];
                    result += ALPHA_NUMERIC_STR[sum % 45];
                    countBits -= 2;
                }
                if (countBits == 1) {
                    alphaNumericString = decodeStr.substr(idx, 6);
                    idx += 6;

                    sum = getDecimal(alphaNumericString);
                    result += ALPHA_NUMERIC_STR[sum % 45];
                }
            } else if (modeBits[1] == '1') {
                countBits = getCountBits(decodeStr, MODE_8_BIT_BYTE, idx);
                len += countBits;
                idx += 8;

                std::string bitString;
                while (countBits) {
                    bitString = decodeStr.substr(idx, 8);
                    idx += 8;

                    sum = getDecimal(bitString);
                    if (sum >= 0x20 && sum <= 0x7e)
                        result += (char)sum;
                    else {
                        result += '\\';

                        int tmp = sum / 16;
                        result += (tmp < 10) ? (char)(tmp + '0') : (char)(tmp - 10 + 'A');

                        tmp = sum % 16;
                        result +=(tmp < 10) ? (char)(tmp + '0') : (char)(tmp - 10 + 'A');
                    }
                    countBits--;
                }
            } else if (modeBits[0] == '1') {
                countBits = getCountBits(decodeStr, MODE_KANJI, idx);
                len += countBits;
                idx += 8;

                std::string bitString;
                while (countBits) {
                    result += '#';
                    bitString = decodeStr.substr(idx, 1);
                    idx += 1;

                    result += bitString[0];
                    for (int i = 0; i < 3; i++) {
                        bitString = decodeStr.substr(idx, 4);
                        idx += 4;

                        sum = getDecimal(bitString);

                        int tmp = sum % 16;
                        result += (tmp < 10) ? (char)(tmp + '0') : (char)(tmp - 10 + 'A');
                    }
                    countBits--;
                }
            } else {
                break;
            }
        }
        std::cout << len << " " << result << std::endl;
    }
    return 0;
}