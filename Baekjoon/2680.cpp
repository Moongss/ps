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
    std::cout << "str : " << str << std::endl;
    if (mode == MODE_NUMERIC) {
        std::string tmp = str.substr(idx, 10);
        std::cout << "TMP : " << tmp << std::endl;
        for (int i = 9; i >= 0; i--) {
            if (tmp[i] == '1')
                result += cur;
            cur *= 2;
        }
    } else if (mode == MODE_ALPHA_NUMERIC) {
        std::string tmp = str.substr(idx, 9);
        std::cout << "TMP : " << tmp << std::endl;
        for (int i = 8; i >= 0; i--) {
            if (tmp[i] == '1')
                result += cur;
            cur *= 2;
        }
    } else if (mode == MODE_8_BIT_BYTE || mode == MODE_KANJI) {
        std::string tmp = str.substr(idx, 8);
        std::cout << "idx : " << idx << ", str.length : " << str.length() << std::endl;
        std::cout << "TMP : " << tmp << std::endl;
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
        getline(std::cin, encodeStr);
        decode(encodeStr);

        size_t idx = 0;
        int len = 0;
        while (idx < decodeStr.length()) {
            std::string modeBits = decodeStr.substr(idx, 4);
            idx += 4;

            std::cout << "modeBits : " << modeBits << std::endl;
            //3 Numeric
            //2 Alphanumeric
            //1 8bitbyte
            //0 kanji
            //x termination
            int countBits;
            if (modeBits[3] == '1') { 
                std::cout << "NUMERIC\n";
                countBits = getCountBits(decodeStr, MODE_NUMERIC, idx);
                std::cout << "countBits : " << countBits << std::endl;
                idx += 10;

                int lastBits = 10;
                if (countBits % 3 == 2) {
                    lastBits = 7;
                } else if (countBits % 3 == 1) {
                    lastBits = 4;
                }

                int loopCnt = countBits / 3 + 1;
                std::string numericString;
                while (loopCnt--) {
                    int currentBits = (loopCnt == 0) ? lastBits : 10;

                    numericString = decodeStr.substr(idx, currentBits);
                    idx += currentBits;

                    int cur = 1;
                    int sum = 0;
                    for (int i = currentBits - 1; i >= 0; i--) {
                        if (numericString[i] == '1')
                            sum += cur;
                        cur *= 2;
                    }
                    result += std::to_string(sum);  
                    len += std::to_string(sum).length();  
                }
                std::cout << "RESULT : " << result << std::endl;
            } else if (modeBits[2] == '1') {
                std::cout << "ALPHANUMER\n";
                countBits = getCountBits(decodeStr, MODE_ALPHA_NUMERIC, idx);
                std::cout << "countBits : " << countBits << std::endl;
                idx += 9;

                int lastBits = (countBits % 2) ? 6 : 11;

                int loopCnt = countBits / 2 + 1;
                std::string alphaNumericString;
                while (loopCnt--) {
                    int currentBits = (loopCnt == 0) ? lastBits : 11;

                    std::cout << "currentBits : " << currentBits << std::endl;
                    alphaNumericString = decodeStr.substr(idx, currentBits);
                    idx += currentBits;

                    int cur = 1;
                    int sum = 0;
                    for (int i = currentBits - 1; i >= 0; i--) {
                        if (alphaNumericString[i] == '1')
                            sum += cur;
                        cur *= 2;
                    }

                    std::cout << "ALPHA sum : " << sum << std::endl;
                    if (sum / 45) {
                        result += ALPHA_NUMERIC_STR[sum / 45];
                        len++;
                    }
                    result += ALPHA_NUMERIC_STR[sum % 45];
                    len++;
                }
                std::cout << "RESULT : " << result << std::endl;
            } else if (modeBits[1] == '1') {
                std::cout << "8BITBYTE\n";
                countBits = getCountBits(decodeStr, MODE_8_BIT_BYTE, idx);
                std::cout << "countBits : " << countBits << std::endl;
                idx += 8;

                int loopCnt = countBits;
                int currentBits = 8;
                std::string bitString;
                while (loopCnt--) {
                    bitString = decodeStr.substr(idx, currentBits);
                    idx += currentBits;

                    int cur = 1;
                    int sum = 0;
                    for (int i = currentBits - 1; i >= 0; i--) {
                        if (bitString[i] == '1')
                            sum += cur;
                        cur *= 2;
                    }

                    if (sum < 0x20 || sum > 0x7e)  {
                        result += "\\";
                        if (sum / 16) {
                            if (sum / 16 < 10)
                                result += sum / 16 + '0';
                            else
                                result += sum / 16 - 10 + 'A';
                        }
                        if (sum % 16 < 10)
                            result += sum % 16 + '0';
                        else
                            result += sum % 16 - 10 + 'A';
                        len++;
                    } else {
                        result += (char)sum;
                        len++;
                    }
                }
            } else if (modeBits[0] == '1') {
                std::cout << "KANJI\n";
                countBits = getCountBits(decodeStr, MODE_KANJI, idx);
                std::cout << "countBits : " << countBits << std::endl;
                idx += 8;

                int loopCnt = countBits;
                int currentBits = 13;
                std::string bitString;
                while (loopCnt--) {
                    bitString = decodeStr.substr(idx, currentBits);
                    idx += currentBits;

                    int cur = 1;
                    int sum = 0;
                    for (int i = currentBits - 1; i >= 0; i--) {
                        if (bitString[i] == '1')
                            sum += cur;
                        cur *= 2;
                    }

                    std::cout << "sum : " << sum << std::endl;
                    result += "#";
                    std::string tmp = "";
                    while (sum > 0) {
                        if (sum % 16 < 10)
                            tmp += sum % 16 + '0';
                        else
                            tmp += sum / 16 - 10 + 'A';
                        sum /= 16;
                    }

                    for (size_t i = tmp.length() - 1; i >= 0; i--) {
                        result += tmp[i];
                    }
                    len++;
                }
            } else {
                std::cout << "NONE\n";
                break;
            }
        }

        std::cout << len << " " << result << std::endl;
    }
    return 0;
}