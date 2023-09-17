#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

int I, N, K;
char ch;
int inkAmount;
int inkPos;
std::string inkString;
std::string commandString;
std::pair<int, int> squarePos;
std::vector<std::pair<int, int> >v;
char map[101][101];

int main() {
    std::cin >> I >> N >> K;
    std::cin >> inkString;

    inkAmount = inkPos = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch;
            std::cin >> ch;
            map[i][j] = ch;
            if (ch == '@')
                squarePos = std::make_pair(i, j);
            if (ch == '#')
                v.push_back(std::make_pair(i, j));
        }
    }

    for (int i = 0; i < K; i++) {
        std::cin >> ch;
        if (ch == 'j')
            inkAmount++;
        if (ch == 'J') {
            for (auto elem : v) {
                if (std::abs(elem.first - squarePos.first) + std::abs(elem.second - squarePos.second) <= inkAmount)
                    map[elem.first][elem.second] = inkString[inkPos];
            }
            inkAmount = 0;
            inkPos = (inkPos + 1) % inkString.length();
        }
        if  (ch == 'R' && squarePos.second + 1 < N && map[squarePos.first][squarePos.second + 1] == '.') { 
            map[squarePos.first][squarePos.second++] = '.';
            map[squarePos.first][squarePos.second] = '@';
        }
        if  (ch == 'L' && squarePos.second - 1 >= 0 && map[squarePos.first][squarePos.second - 1] == '.') {
            map[squarePos.first][squarePos.second--] = '.';
            map[squarePos.first][squarePos.second] = '@';
        }
        if  (ch == 'U' && squarePos.first - 1 >= 0 && map[squarePos.first - 1][squarePos.second] == '.') {
            map[squarePos.first--][squarePos.second] = '.';
            map[squarePos.first][squarePos.second] = '@';
        }
        if  (ch == 'D' && squarePos.first + 1 < N && map[squarePos.first + 1][squarePos.second] == '.') {
            map[squarePos.first++][squarePos.second] = '.';
            map[squarePos.first][squarePos.second] = '@';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}