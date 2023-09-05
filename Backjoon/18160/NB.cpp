#include "NB.h"
#include <iostream>
#include <vector>
#include <algorithm>

int gamePlayTime;
int len;
std::vector<int> numVector;
std::vector<bool> numPossibility;

void init(int T, int N) {
    // init
    len = N;

    int start = (len == 3) ? 12 : 123;
    int end = (len == 3) ? 987 : 9876;

    for (int num = start; num <= end; num++) {
        int unit[5] = {0, };

        unit[4] = num / 1000;
        unit[3] = (num % 1000) /100;
        unit[2] = (num % 100) / 10;
        unit[1] = (num % 10);

        if (unit[1] == unit[2] || unit[1] == unit[3] || unit[2] == unit[3])
            continue;
        if (len == 4 && (unit[1] == unit[4] || unit[2] == unit[4] || unit[3] == unit[4]))
            continue;

        // if (num <= 1000)
        //     std::cout << "0";
        // std::cout << num << " ";
        numVector.push_back(num); // vector elem has possiblity to answer
        numPossibility.push_back(true);
    }
}

void filterOut(std::pair<int, int> result, int numIdx){ 
    
    for (int i = 0; i < numVector.size(); i++) {
        int A = numVector[numIdx];
        int B = numVector[i];
        int ballCnt = 0;
        int strikeCnt = 0;
        int num[10] = {0, };

        if (numPossibility[i]) {
            for (int j = 0; j < len; j++) {

                // std::cout << "A : |" << A << "|, B : |" << B << "| " << std::endl;
                if (A % 10 == B % 10) {
                    strikeCnt++;
                }
                else {
                    num[A % 10]++;
                    num[B % 10]++;
                }

                if (num[A % 10] == 2) ballCnt++;
                if (num[B % 10] == 2) ballCnt++;

                A /= 10;
                B /= 10;
            }

            // std::cout << "|| strike: " << strikeCnt << ", ballCnt : " << ballCnt << std::endl;
            if (strikeCnt != result.first || ballCnt != result.second)
                numPossibility[i] = false;
        }
    }
}

void game() {
    // game
    for (int i = 0; i < numVector.size(); i++)
        numPossibility[i] = true;

    while (true) {
        std::string numStr = "";
        int numIdx;

        for (int i = 0; i < numVector.size(); i++) {

            if (!numPossibility[i])
                continue;

            numIdx = i;
            int num = numVector[i];
            int unit[5] = {0, };

            unit[4] = num / 1000;
            unit[3] = (num % 1000) / 100;
            unit[2] = (num % 100) / 10;
            unit[1] = (num % 10);

            if (len == 4)
                numStr += unit[4] + '0';
            numStr += unit[3] + '0';
            numStr += unit[2] + '0';
            numStr += unit[1] + '0';
            break;
        }

        std::pair<int, int> result = guess(numStr);
        if (result.first == len) return;
        
        numPossibility[numIdx] = false;
        filterOut(result, numIdx);
    }
}




#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "NB.h"
using namespace std;
string A;
int cnt;
bool solve;
void wa() {
    cout << "WA\n";
    exit(1);
}
pair<int,int> guess(string B) {
    if (A.length() != B.length()) {
        wa();
    }
    if (solve) {
        wa();
    }
    cnt += 1;
    if (cnt > 9) {
        wa();
    }
    int strike = 0;
    int ball = 0;
    vector<int> index_a(10, -1);
    vector<int> index_b(10, -1);
    for (int i=0; i<A.length(); i++) {
        if (!('0' <= B[i] && B[i] <= '9')) {
            wa();
        }
        int a = A[i]-'0';
        int b = B[i]-'0';
        index_a[a] = i;
        if (index_b[b] != -1) {
            wa();
        }
        index_b[b] = i;
    }
    for (int i=0; i<=9; i++) {
        if (index_a[i] == -1 || index_b[i] == -1) {
            continue;
        }
        if (index_a[i] == index_b[i]) {
            strike += 1;
        } else {
            ball += 1;
        }
    }
    if (strike == (int)A.length() && ball == 0) {
        solve = true;
    }
    return make_pair(strike, ball);
}
int main() {
    int T, N;
    cin >> T >> N;
    init(T, N);
    while (T--) {
        cin >> A;
        solve = false;
        cnt = 0;
        game();
        if (solve == false) {
            wa();
        }
    }
    cout << "AC\n";
    return 0;
}
