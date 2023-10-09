#include <iostream>

using ll = long long;
using ld = long double;

int a, b, c;
int gV[3][3];
int v[3];
int gcd(int a, int b)
{
	int c;

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main() {
    std::cin >> a >> b >> c >> v[0] >> v[1] >> v[2];

    int veloLcm = lcm(lcm(v[0], v[1]), v[2]);
    for (int i = 0; i < 3; i++) {
        int curV = veloLcm/v[i];
        gV[i][0] = curV * a;
        gV[i][1] = curV * b;
        gV[i][2] = curV * c;
    }

    bool post = false;
    bool mart = false;

    int current = 0;
    int bag = 0;
    ll sum = 0;
    while (!post || !mart) {
        if (current == 0) {
            if (gV[bag][1] < gV[bag][2]) {
                current = 1; //mart
                sum += gV[bag][1];
            } else {
                current = 2; //post
                sum += gV[bag][2];
            }
        }
        else if (current == 1) { //mart
            if (!mart) {
                mart = true;
                bag++;
            }
            if (gV[bag][0] < gV[bag][2]) {
                current = 0; //home
                sum += gV[bag][0];
            } else {
                current = 2; //mart
                sum += gV[bag][2];
            }
        }
        else if (current == 2) {
            if (!post) {
                post = true;
                bag++;
            }
            if (gV[bag][0] < gV[bag][1]) {
                current = 0; //home
                sum += gV[bag][0];
            } else {
                current = 1; //post
                sum += gV[bag][1];
            }
        }
    }
}