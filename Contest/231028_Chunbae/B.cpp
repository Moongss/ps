#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N;
string str;
int upperRainbow[7] = {0, };
int lowerRainbow[7] = {0, };

int main() {
    fastio;
    cin >> N >> str;
    for (int i = 0; i < N; i++) {
        if (str[i] == 'R') upperRainbow[0]++;
        if (str[i] == 'O') upperRainbow[1]++;
        if (str[i] == 'Y') upperRainbow[2]++;
        if (str[i] == 'G') upperRainbow[3]++;
        if (str[i] == 'B') upperRainbow[4]++;
        if (str[i] == 'I') upperRainbow[5]++;
        if (str[i] == 'V') upperRainbow[6]++;

        if (str[i] == 'r') lowerRainbow[0]++;
        if (str[i] == 'o') lowerRainbow[1]++;
        if (str[i] == 'y') lowerRainbow[2]++;
        if (str[i] == 'g') lowerRainbow[3]++;
        if (str[i] == 'b') lowerRainbow[4]++;
        if (str[i] == 'i') lowerRainbow[5]++;
        if (str[i] == 'v') lowerRainbow[6]++;
    }

    bool upperFlag, lowerFlag;
    upperFlag = lowerFlag = true;
    for (int i = 0; i < 7; i++) {
        if (!upperRainbow[i]) upperFlag = false;
        if (!lowerRainbow[i]) lowerFlag = false;
    }

    if (upperFlag && lowerFlag)
        cout << "YeS" << endl;
    else if (upperFlag)
        cout << "YES" << endl;
    else if (lowerFlag)
        cout << "yes" << endl;
    else
        cout << "NO!" << endl;
    return 0;
}