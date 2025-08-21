#include <algorithm>
#include <iostream>
#include <vector>

typedef long double ld;

std::vector<std::pair<ld, ld>> save;
int N;

ld getAbs(ld a) {
  if (a >= 0)
    return (a);
  return (-a);
}

ld getTriangleArea(std::pair<ld, ld> dirA, std::pair<ld, ld> dirB) {

  std::pair<ld, ld> tmp = {dirA.first * dirB.second, dirB.first * dirA.second};

  return (getAbs(tmp.first - tmp.second) / 2);
}

int getSign(std::pair<ld, ld> dirA, std::pair<ld, ld> dirB) {
  long result = dirA.first * dirB.second - dirA.second * dirB.first;

  if (result < 0)
    return -1;
  return 1;
}

int main() {
  ld space = 0; //기존 long double, 덧셈 도중에 부동소수점의 문제로 에러
                //가능성 있음. -> 아니었고, 처음부터 통일시켜준다면?
  std::pair<int, int> originCoord;

  std::cin >> N;
  std::cin >> originCoord.first >> originCoord.second;

  ld x, y;
  for (int i = 0; i < N - 1; i++) {
    std::cin >> x >> y;
    save.push_back({x, y});
  }

  for (int i = 0; i < N - 2; i++) {
    // use CCW
    std::pair<ld, ld> dirA = {save[i].first - originCoord.first,
                              save[i].second - originCoord.second};
    std::pair<ld, ld> dirB = {save[i + 1].first - originCoord.first,
                              save[i + 1].second - originCoord.second};
    space += getTriangleArea(dirA, dirB) * getSign(dirA, dirB);
  }

  if (space < 0)
    space *= -1;
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << space << std::endl;
  return 0;
}